/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA4
* Graph.c
* Implementation file for Graph ADT
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"

// structs --------------------------------------------------------------------

// private GraphObj type
typedef struct GraphObj{
	int order;
	List *adj;
	int *colour;	//0 = white, 1 = grey, -1 = black
	int *parent;
	int *discover;
   int *finish;
	int size;
} GraphObj;

int alreadyExists(List L, int u);
void visit(Graph G, int x, int* time, List S);

// Constructors-Destructors ---------------------------------------------------

// newGraph()
// Returns reference to new empty Graph object.
Graph newGraph(int n) {
   Graph G = malloc(sizeof(GraphObj));   // mallocs memory for the Graph item

   // initialise int variables
   G->order = n;
   G->size = 0;

   //initialise array varibales
   G->adj = (List*)malloc((n+1)*sizeof(List));
   G->colour = (int*)malloc((n+1)*sizeof(int));
   G->parent = (int*)malloc((n+1)*sizeof(int));
   G->discover = (int*)malloc((n+1)*sizeof(int));
   G->finish = (int*)malloc((n+1)*sizeof(int));

   // initialise array variables to default states
   int i;
   for (i = 1; i < n+1; i++) {
   		G->adj[i] = newList();	// add empty lists to adj
   		G->colour[i] = 0;		// set colour to white
   		G->parent[i] = NIL;		// set parent to NIL
   		G->discover[i] = UNDEF;		// set discover time to 0
         G->finish[i] = UNDEF;      // set finish time to 0
   }

   return(G);                          // returns the empty Graph
}

void freeGraph(Graph* pG) {
   if( pG!=NULL && *pG!=NULL ){
   		// write a loop to free all the Lists in adj
   		int i;
   		for (i = 1; i < ((*pG)->order)+1; i++) {
   			freeList(&((*pG)->adj[i]));
   		}
   		free((*pG)->adj);
   		free((*pG)->discover);
         free((*pG)->finish);
   		free((*pG)->colour);
   		free((*pG)->parent);
      	free(*pG);
      	*pG = NULL;
   }
}

// Access functions -----------------------------------------------------------

int getOrder(Graph G) {
	if( G==NULL ){
      printf("Graph Error: calling getOrder() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   	}
	return G->order;
}
int getSize(Graph G) {
	if( G==NULL ){
      printf("Graph Error: calling getSize() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   	}
	return G->size;
}

int getParent(Graph G, int u) {
   if( G==NULL ){
      printf("Graph Error: calling getParent() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
      }
      if ((u < 1) || (u > getOrder(G))) {
     printf("Graph Error: calling getParent() with invalid vertex\n");
      exit(EXIT_FAILURE);
      }
   return G->parent[u];
}

int getDiscover(Graph G, int u) {
   if( G==NULL ){
      printf("Graph Error: calling getDiscover() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
      }
      if ((u < 1) || (u > getOrder(G))) {
     printf("Graph Error: calling getDiscover() with invalid vertex\n");
      exit(EXIT_FAILURE);
      }
   return G->discover[u];
}

int getFinish(Graph G, int u) {
   if( G==NULL ){
      printf("Graph Error: calling getFinish() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
      }
      if ((u < 1) || (u > getOrder(G))) {
     printf("Graph Error: calling getFinish() with invalid vertex\n");
      exit(EXIT_FAILURE);
      }
   return G->finish[u];
}

int compareGraph(Graph G, Graph F) {
   if( G==NULL ){
      printf("Graph Error: calling compareGraph() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   }
   if( F==NULL ){
      printf("Graph Error: calling compareGraph() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   }
   if (G->order != F->order || G->size != F->size) {
      return 0;
   }
   int i;
   for (i = 1; i <= G->order; i++) {
      if (!equals(G->adj[i], F->adj[i])) {
         return 1;
      }
   }
   return 2;
}

// Manipulation procedures ----------------------------------------------------

void makeNull(Graph G) {
   if( G==NULL ){
      printf("Graph Error: calling makeNull() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
      }
   int i;
   for (i = 1; i < (G->order)+1; i++) {
      clear(G->adj[i]);
      G->colour[i] = 0;
      G->discover[i] = 0;
      G->finish[i] = 0;
      G->parent[i] = NIL;
   }
   G->size = 0;
}

void addEdge(Graph G, int u, int v) {
   if( G==NULL ){
      printf("Graph Error: calling addEdge() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
      }
      if ((u < 1) || (u > getOrder(G))) {
     printf("Graph Error: calling addEdge() with invalid vertex\n");
      exit(EXIT_FAILURE);
      }
      if ((v < 1) || (v > getOrder(G))) {
     printf("Graph Error: calling addEdge() with invalid vertex\n");
      exit(EXIT_FAILURE);
      }
      if (u == v) {
        printf("Graph Error: calling addEdge() with the same verticies\n");
      exit(EXIT_FAILURE);
      }

   moveFront(G->adj[v]);
      if (index(G->adj[v]) < 0) {
         append((G->adj[v]), u);
         G->size += 1;
      }
      else if(!alreadyExists(G->adj[v], u)) {
         moveFront(G->adj[v]);
         while(index(G->adj[v]) >= 0) {
            if (get(G->adj[v]) > u) {
               insertBefore(G->adj[v], u);
               break;
            } else {
               moveNext(G->adj[v]);
            }
         }
         if (!alreadyExists(G->adj[v], u)) {
            append(G->adj[v], u);
         }
         G->size += 1;
   }

      moveFront(G->adj[u]);
   if (index(G->adj[u]) < 0) {
         append((G->adj[u]), v);
      }
      else if(!alreadyExists(G->adj[u], v)) {
         moveFront(G->adj[u]);
         while(index(G->adj[u]) >= 0) {
            if (get(G->adj[u]) > v) {
               insertBefore(G->adj[u], v);
               break;
            } else {
               moveNext(G->adj[u]);
            }
         }
         if (!alreadyExists(G->adj[u], v)) {
            append(G->adj[u], v);
         }
   }
}

void addArc(Graph G, int u, int v) {  // u->v
   if( G==NULL ){
      printf("Graph Error: calling addArc() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
      }
      if ((u < 1) || (u > getOrder(G))) {
     printf("Graph Error: calling addArc() with invalid vertex - u: %d\n", u);
      exit(EXIT_FAILURE);
      }
      if ((v < 1) || (v > getOrder(G))) {
     printf("Graph Error: calling addArc() with invalid vertex - v: %d\n", v);
      exit(EXIT_FAILURE);
      }

      moveFront(G->adj[u]);
   if (index(G->adj[u]) < 0) {
         append((G->adj[u]), v);
         G->size += 1;
      }
      else if(!alreadyExists(G->adj[u], v)) {
         moveFront(G->adj[u]);
         while(index(G->adj[u]) >= 0) {
            if (get(G->adj[u]) > v) {
               insertBefore(G->adj[u], v);
               break;
            } else {
               moveNext(G->adj[u]);
            }
         }
         if (!alreadyExists(G->adj[u], v)) {
            append(G->adj[u], v);
         }
         G->size += 1;
   }
}

void DFS(Graph G, List S) {
   if( G==NULL ){
      printf("Graph Error: calling DFS() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   }
   if( S==NULL ){
      printf("Graph Error: calling DFS() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (length(S) != G->order) {
      printf("Graph Error: calling DFS() with length(S) != n\n");
      exit(EXIT_FAILURE);
   }
   int i;
   for (i = 1; i <= G->order; i++) { //0 = white, 1 = gray, -1 = black
      G->colour[i] = 0;
      G->parent[i] = NIL;
   }
   int time = 0;
   moveFront(S);
   while(index(S) >= 0) {
      int x = get(S);
      if (G->colour[x] == 0) {
         visit(G, x, &time, S);
      }
      moveNext(S);
   }
   while(length(S) > G->order) {
      deleteFront(S);
   }
   moveBack(S);
   while(index(S) >= 0) {
      append(S, get(S));
      movePrev(S);
   }
   while(length(S) > G->order) {
      deleteFront(S);
   }
}

void visit(Graph G, int x, int* time, List S) {
   G->discover[x] = ++(*time);
   G->colour[x] = 1;
   moveFront(G->adj[x]);
   while (index(G->adj[x]) >= 0) {
      int y = get(G->adj[x]);
      if (G->colour[y] == 0) {
         G->parent[y] = x;
         visit(G, y, time, S);
      }
      moveNext(G->adj[x]);
   }
   G->colour[x] = -1;
   G->finish[x] = ++(*time);
   append(S, x);
}

// Other ----------------------------------------------------
void printGraph(FILE* out, Graph G) {
   if( G==NULL ){
      printf("Graph Error: calling printGraph() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   }
      int i;
      for (i = 1; i < (G->order); i++) {
         fprintf(out, "%d: ", i);
         printList(out, G->adj[i]);
         fprintf(out, "\n");
      }
      fprintf(out, "%d: ", G->order);
      printList(out, G->adj[G->order]);
}

Graph transpose(Graph G) {
   if( G==NULL ){
      printf("Graph Error: calling tranpose() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   }
   Graph t = newGraph(G->order);
   int i;
   for (i = 1; i <= getOrder(G); i++) {
      moveFront(G->adj[i]);
      while (index(G->adj[i]) >= 0) {
         addArc(t, get(G->adj[i]), i);
         moveNext(G->adj[i]);
      }
   }
   return t;
}
Graph copyGraph(Graph G) {
   if( G==NULL ){
      printf("Graph Error: calling copyGraph() on NULL Graph reference\n");
      exit(EXIT_FAILURE);
   }
   Graph copy = newGraph(G->order);
   int i;
   for (i = 1; i <= getOrder(G); i++) {
      moveFront(G->adj[i]);
      while (index(G->adj[i]) >= 0) {
         addArc(copy, i, get(G->adj[i]));
         moveNext(G->adj[i]);
      }
   }
   return copy;
}

int alreadyExists(List L, int u) {
   if( L==NULL ){
      fprintf(stdout, "List Error: calling alreadyExists() on NULL List reference\n");
      exit(EXIT_FAILURE);
    }
      moveFront(L);
      while(index(L) >= 0) {
         if(get(L) == u) {
            return 1;
         }
         moveNext(L);
      }
      return 0;
}