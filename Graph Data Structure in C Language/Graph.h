/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA4
* Graph.h
* Header file for Graph ADT
*********************************************************************************/

#ifndef Graph_H_INCLUDE_
#define Graph_H_INCLUDE_

#define NIL 0
#define UNDEF -1

#include <stdio.h>
#include "List.h"

// Exported type --------------------------------------------------------------
typedef struct GraphObj* Graph;

// Constructors-Destructors ---------------------------------------------------

// newGraph()
// Returns reference to new empty Graph object. 
Graph newGraph(int n);

// freeGraph()
// Frees all heap memory associated with Graph *pN, and sets *pN to NULL.
void freeGraph(Graph* pG);

// Access functions -----------------------------------------------------------

// getOrder()
// Returns the order (number of verticies) of Graph G
int getOrder(Graph G);

// getSize()
// Returns the size (number of edges) of Graph G
int getSize(Graph G);

// getParent()
// Returns the parent of vertex u of Graph G
// Pre: u is >= 1 and <= order of G
int getParent(Graph G, int u);

// getDiscover()
// Returns the discovery time of vertex u
// Pre: u is >= 1 and <= order of G
int getDiscover(Graph G, int u);

// getFinish()
// Returns the finish time of vertex u
// Pre: u is >= 1 and <= order of G
int getFinish(Graph G, int u);

// compareGraph()
// Returns true (1) is the graphs are the same. False (0) otherwise.
int compareGraph (Graph G, Graph F);

// Manipulation procedures ----------------------------------------------------

// makeNull()
// resets the graph to it's original blank state
void makeNull(Graph G);

// addEdge()
// Adds an edge to the Graph G connecting vertext u to v and v to u
// pre: u and v are within range and u != v
void addEdge(Graph G, int u, int v);

// addArc()
// Adds a directed edge to the Graph G connecting vertext u to v
// pre: u and v are within range and u != v
void addArc(Graph G, int u, int v);

// DFS()
// Performs a DFS on Graph G and 
// Pre: len(s) == n
// Post: s contains the list of verticies in decreasing finish times
void DFS(Graph G, List s);

// Other ----------------------------------------------------
void printGraph(FILE* out, Graph G);
Graph transpose(Graph G);
Graph copyGraph(Graph G);

#endif