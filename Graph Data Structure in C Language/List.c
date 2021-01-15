/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA4
* List.c
* Implementation file for List ADT
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "List.h"

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   LIST_ELEMENT data;               // store the data
   struct NodeObj* next;   // store pointer to the next item in the list
   struct NodeObj* prev;   // store pointer to the prev item in the list
   int index;              // store the index of this item in the list
} NodeObj;

// private Node type
typedef NodeObj* Node;     // pointer to NodeObj called Node

// private List type
typedef struct ListObj{
   int length;             // stores the length of the list
   Node front;             // stores the item at the front of the list
   Node back;              // stores the item at the back of the list
   Node cursor;            // stores the cursor item
}ListObj;


// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object.
List newList(){
   List L = malloc(sizeof(ListObj));   // mallocs memory for the list item
   L->length = 0;                      // initialises length to 0
   L->front = NULL;                    // sets the front item to null
   L->back = NULL;                     // sets the back item to null
   L->cursor = NULL;                   // sets the cursor item to null/undefined
   return(L);                          // returns the empty list
}

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
Node newNode(LIST_ELEMENT data){
   Node N = malloc(sizeof(NodeObj));   // mallocs memory for the node item
   N->data = data;                     // sets the data
   N->next = NULL;                     // sets the next item to null
   N->prev = NULL;                     // sets the prev item to null
   N->index = -1;                      // sets index to -1 by default
   return(N);                          // returns the empty node
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL){
   clear(*pL);
   free(*pL);
   *pL = NULL;
}

// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of the List.
// Pre: !isEmpty(L)
LIST_ELEMENT front(List L){
   if( L==NULL ){
      printf("List Error: calling front() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling front() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   return(L->front->data);
}

// back()
// Returns the value at the back of the List.
// Pre: !isEmpty(L)
LIST_ELEMENT back(List L){
   if( L==NULL ){
      printf("List Error: calling back() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling back() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   return(L->back->data);
}

// length()
// Returns the length of Q.
int length(List L){
   if( L==NULL ){
      printf("List Error: calling length() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   return(L->length);
}

// isEmpty()
// Returns true (1) if Q is empty, otherwise returns false (0)
int isEmpty(List L){
   if( L==NULL ){
      printf("List Error: calling isEmpty() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   return(L->length==0);
}

// index();
// returns the index of the cursor element
int index(List L) {
   if( L==NULL ){
      printf("List Error: calling index() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (L-> cursor == NULL) {
      return -1;
   }
   return (L->cursor->index);
}

// get();
// returns the cursor element of the list
LIST_ELEMENT get(List L) {
   if( L==NULL ){
      printf("List Error: calling get() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling get() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   if (index(L) < 0) {
      printf("List Error: calling get() with an undefined cursor\n");
      exit(EXIT_FAILURE);
   }
   return (L->cursor->data);
}

// equals();
// Returns true (1) iff Lists A and B are in same
// state, and returns false (0) otherwise.
int equals(List A, List B) {
   if (length(A) != length(B)) {       // checks if the lengths differ
      return(0);
   }
   Node ACursor = A->cursor;           // saves the cursor for A
   Node BCursor = B->cursor;           // saves the cursor for B

   // the next chunk of code iterates through both lists and compares each item
   // returns 0 if any one item differs
   moveFront(A);
   moveFront(B);
   int i;
   for (i = 0; i < length(A); i++) {
      if(get(A) != get(B)) {
         A->cursor = ACursor;
         B->cursor = BCursor;
         return(0);
      }
      moveNext(A);
      moveNext(B);
   }
   A->cursor = ACursor;    // restores cursor of A
   B->cursor = BCursor;    // restores cursor of B
   return(1);              // returns true
}


// Manipulation procedures ----------------------------------------------------

// clear(List L)
// Resets L to its original empty state.
void clear(List L) {
   if( L==NULL ){
      printf("List Error: calling clear() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   int i;
   Node n = L->front;
   for (i= 0; i<length(L); i++){ // free all nodes
      L->front = n->next;
      freeNode(&n);
      n = L->front;
   }
   L->front = L->back = NULL;    // set everything to null
   L->length = 0;
   L->cursor = NULL;
}

// moveFront(List L);
// If L is non-empty, sets cursor under the front element,
// otherwise does nothing.
void moveFront(List L) {
   if( L==NULL ){
      printf("List Error: calling moveFront() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (!isEmpty(L)) {
      L->cursor = L->front;
   }
}

// moveBack(List L);
// If L is non-empty, sets cursor under the back element,
// otherwise does nothing.
void moveBack(List L) {
   if( L==NULL ){
      printf("List Error: calling moveBack() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (!isEmpty(L)) {
      L->cursor = L->back;
   }
}


// movePrev(L)
// If cursor is defined and not at front, move cursor one
// step toward the front of L; if cursor is defined and at
// front, cursor becomes undefined; if cursor is undefined
// do nothing
void movePrev(List L) {
   if( L==NULL ){
      printf("List Error: calling movePrev() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (L->cursor!=NULL && L->cursor!=L->front){
      L->cursor = L->cursor->prev;
   }
   else if (L->cursor == L->front){
      L->cursor = NULL;
   }
}

// moveNext(L);
// If cursor is defined and not at back, move cursor one
// step toward the back of L; if cursor is defined and at
// back, cursor becomes undefined; if cursor is undefined
// do nothing
void moveNext(List L) {
   if( L==NULL ){
      printf("List Error: calling moveNext() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (L->cursor!=NULL && L->cursor!=L->back){
      L->cursor = L->cursor->next;
   }
   else if (L->cursor == L->back){
      L->cursor = NULL;
   }
}

// prepend(L, data);
// Insert new element into L. If L is non-empty,
// insertion takes place before front element.
void prepend(List L, LIST_ELEMENT data) {
   if( L==NULL ){
      printf("List Error: calling prepend() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (isEmpty(L)) {
      L->front = L->back = newNode(data);
      L->front->index = 0;
      L->length = 1;
   } else {
      L->front->prev = newNode(data);
      L->front->prev->next = L->front;
      L->front = L->front->prev;
      L->length = L->length +1;

      int i;
      Node n = L->front;
      for (i = 0; i < length(L); i++) {
         n->index = i;
         n = n->next;
      }
   }
}

// append(L, data);
// Insert new element into L. If L is non-empty,
// insertion takes place after back element.
void append(List L, LIST_ELEMENT data) {
   if( L==NULL ){
      printf("List Error: calling append() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (isEmpty(L)) {
      L->front = L->back = newNode(data);
      L->front->index = 0;
      L->length = 1;
   } else {
      L->back->next = newNode(data);
      L->back->next->prev = L->back;
      L->back = L->back->next;
      L->length = L->length+1;
      L->back->index = L->length-1;
   }
}

// insertBefore(List L, int data);
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, LIST_ELEMENT data) {
   if( L==NULL ){
      printf("List Error: calling insertBefore() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   if (index(L) < 0) {
      printf("List Error: calling insertBefore() with undefined cursor\n");
      exit(EXIT_FAILURE);
   }
   if (L->cursor == L->front) {
      prepend(L, data);
   } else {
      L->cursor->prev->next = newNode(data);
      L->cursor->prev->next->next = L->cursor;
      L->cursor->prev->next->prev = L->cursor->prev;
      L->cursor->prev = L->cursor->prev->next;
      L->length = L->length+1;

      int i;
      Node n = L->cursor->prev;
      for (i = L->cursor->index; i < length(L); i++) {
         n->index = i;
         n = n->next;
      }
   }
}

// insertAfter(List L, int data);
// Insert new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, LIST_ELEMENT data) {
   if( L==NULL ){
      printf("List Error: calling insertAfter() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling insertAfter() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   if (index(L) < 0) {
      printf("List Error: calling insertAfter() with undefined cursor\n");
      exit(EXIT_FAILURE);
   }
   if (L->cursor == L->back) {
      append(L, data);
   } else {
      L->cursor->next->prev = newNode(data);
      L->cursor->next->prev->prev = L->cursor;
      L->cursor->next->prev->next = L->cursor->next;
      L->cursor->next = L->cursor->next->prev;
      L->length = L->length+1;

      int i;
      Node n = L->cursor->next;
      for (i = L->cursor->index+1; i < length(L); i++) {
         n->index = i;
         n = n->next;
      }
   }
}

// deleteFront(List L);
// Delete the front element. Pre: length()>0
LIST_ELEMENT deleteFront(List L) {
   if( L==NULL ){
      printf("List Error: calling deleteFront() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (isEmpty(L)) {
      printf("List Error: calling deleteFront() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   if (L->cursor == L->front) {
      L->cursor = NULL;
   }

   LIST_ELEMENT frontData = L->front->data;
   if (length(L) < 2) {
      freeNode(&(L->front));
      L->front = NULL;
      L->length = L->length-1;
   } else {
      L->front = L->front->next;
      freeNode(&(L->front->prev));
      L->front->prev = NULL;
      L->length = L->length-1;

      int i;
      Node n = L->front;
      for (i = 0; i<length(L);i++) {
         n->index = i;
         n = n->next;
      }
   }
   return frontData;
}

// deleteBack(List L);
// Delete the back element. Pre: length()>0
void deleteBack(List L) {
   if( L==NULL ){
      printf("List Error: calling deleteBack() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (isEmpty(L)) {
      printf("List Error: calling deleteBack() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   if (L->cursor == L->back) {
      L->cursor = NULL;
   }
   if (length(L) == 1) {
      clear(L);
   } else {
      L->back = L->back->prev;
      L->back->next->prev = NULL;
      freeNode(&(L->back->next));
      L->back->next = NULL;
      L->length = L->length-1;
   }
}

// delete(List L);
// Delete cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L) {
   if( L==NULL ){
      printf("List Error: calling delete() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (isEmpty(L)) {
      printf("List Error: calling delete() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   if (index(L) < 0) {
      printf("List Error: calling delete() with undefined cursor\n");
      exit(EXIT_FAILURE);
   }
   if (length(L) == 1) {
      clear(L);
   } else if (L->cursor == L->front) {
      deleteFront(L);
   } else if (L->cursor == L->back) {
      deleteBack(L);
   } else {
      L->cursor->prev->next = L->cursor->next;
      L->cursor->next->prev = L->cursor->prev;
      L->length = L->length-1;

      int i;
      Node n = L->cursor->next;
      for (i = L->cursor->index; i<length(L);i++) {
         n->index = i;
         n = n->next;
      }

      freeNode(&(L->cursor));
      L->cursor = NULL;
   }
}

// copyList(List L);
// Returns a new List representing the same integer
// sequence as L. The cursor in the new list is undefined,
// regardless of the state of the cursor in L. The state
// of L is unchanged.
List copyList(List L) {
   List copy = newList();
   
   Node Cursor = L->cursor;   // save the old cursor
   moveFront(L);
   
   int i;
   for (i=0;i<length(L);i++) {
      append(copy, get(L));
      if (L->cursor == Cursor) {
         copy->cursor = copy->back;
      }
      moveNext(L);
   }
   L->cursor = Cursor;
   return(copy);
}

// set(List L, LIST_ELEMENT x)
// Overrides the cursor element with the new element X
void set(List L, LIST_ELEMENT x) {
	if( L==NULL ){
      printf("List Error: calling set() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( index(L) < 0 ){
      printf("List Error: calling set() with undefined cursor\n");
      exit(EXIT_FAILURE);
   }
   L->cursor->data = x;
}

// printList(List L);
// prints the list
void printList(FILE* out, List L) {
   if( L==NULL ){
      fprintf(out, "List Error: calling printList() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if (length(L) == 0) {
      return;
   }
   int i;
   Node n = L->front;
   for (i = 0; i<length(L)-1;i++) {
      fprintf(out,"%ld ", n->data);
      n = n->next;
   }
   fprintf(out,"%ld", n->data);
}

// printindex(List A)
// prints the indices of the list to make sure
// they are being managed correctly
// void printindex(List L) {
//    Node Cursor = L->cursor;
//    moveFront(L);
//    int i;
//    for (i = 0; i < length(L); i++) {
//       printf("%d ", L->cursor->index);
//       moveNext(L);
//    }
//    printf("\n");
//    L->cursor = Cursor;
// }