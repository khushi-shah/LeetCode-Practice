/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA4
* List.h
* Header file for List ADT
*********************************************************************************/

#ifndef List_H_INCLUDE_
#define List_H_INCLUDE_

#define LIST_ELEMENT long

// Exported type --------------------------------------------------------------
typedef struct ListObj* List;

// Constructors-Destructors ---------------------------------------------------

// newList()
// Returns reference to new empty List object. 
List newList();

// freeList()
// Frees all heap memory associated with List *pQ, and sets *pQ to NULL.
void freeList(List* pL);

// Access functions -----------------------------------------------------------

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
LIST_ELEMENT front(List L);

// back()
// Returns the value at the back of L.
// Pre: !isEmpty(L)
LIST_ELEMENT back(List L);

// length()
// Returns the length of L.
int length(List L);

// isEmpty()
// Returns true (1) if L is empty, otherwise returns false (0).
int isEmpty(List L);

// index();
// returns the index of the cursor element
int index(List L);

// get();
// returns the cursor element of the list
LIST_ELEMENT get(List L);

// equals();
// Returns true (1) iff Lists A and B are in same
// state, and returns false (0) otherwise.
int equals(List A, List B);


// Manipulation procedures ----------------------------------------------------
// clear(List L)
// Resets L to its original empty state.
void clear(List L);

// moveFront(List L);
// If L is non-empty, sets cursor under the front element,
// otherwise does nothing.
void moveFront(List L);

// moveBack(List L);
// If L is non-empty, sets cursor under the back element,
// otherwise does nothing.
void moveBack(List L);

// movePrev(L)
// If cursor is defined and not at front, move cursor one
// step toward the front of L; if cursor is defined and at
// front, cursor becomes undefined; if cursor is undefined
// do nothing
void movePrev(List L);

// moveNext(L);
// If cursor is defined and not at back, move cursor one
// step toward the back of L; if cursor is defined and at
// back, cursor becomes undefined; if cursor is undefined
// do nothing
void moveNext(List L);

// prepend(L, data);
// Insert new element into L. If L is non-empty,
// insertion takes place before front element.
void prepend(List L, LIST_ELEMENT data);

// append(L, data);
// Insert new element into L. If L is non-empty,
// insertion takes place after back element.
void append(List L, LIST_ELEMENT data);

// insertBefore(List L, LIST_ELEMENT data);
// Insert new element before cursor.
// Pre: length()>0, index()>=0
void insertBefore(List L, LIST_ELEMENT data);

// insertAfter(List L, LIST_ELEMENT data);
// Insert new element after cursor.
// Pre: length()>0, index()>=0
void insertAfter(List L, LIST_ELEMENT data);

// deleteFront(List L);
// Delete the front element. Pre: length()>0
LIST_ELEMENT deleteFront(List L);

// deleteBack(List L);
// Delete the back element. Pre: length()>0
void deleteBack(List L);

// delete(List L);
// Delete cursor element, making cursor undefined.
// Pre: length()>0, index()>=0
void delete(List L);

// copyList(List L);
// Returns a new List representing the same integer
// sequence as L. The cursor in the new list is undefined,
// regardless of the state of the cursor in L. The state
// of L is unchanged.
List copyList(List L);

// set(List L, LIST_ELEMENT x)
// Overrides the cursor element with the new element X
void set(List L, LIST_ELEMENT x);

// printList(List L);
// prints the list
void printList(FILE* out, List L);

// printIndex(List A)
// prints the indices of the list to make sure
// they are being managed correctly
// ONLY FOR TESTING
// void printIndex(List L);

#endif