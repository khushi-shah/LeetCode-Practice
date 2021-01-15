/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA5
* List.cpp
* Implements the List ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include"List.h"

#define NIL -1

using namespace std;

// Private Constructor --------------------------------------------------------

// Node constructor
List::Node::Node(int x){
   data = x;
   next = nullptr;
   prev = nullptr;
}

// Class Constructors & Destructors -------------------------------------------

// Creates a new List in the empty state.
List::List(){
   frontDummy = new Node(NIL);
   backDummy = new Node(NIL);
   num_elements = 0;
   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;
}

// Copy Constructor.
List::List(const List& L){
   // make this an empty List
   frontDummy = new Node(NIL);
   backDummy = new Node(NIL);
   num_elements = 0;
   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;

   // load elements of L into this
   Node* N = L.frontDummy->next;
   while( N != nullptr ){
      this->insertBefore(N->data);
      N = N->next;
   }
   while(this->pos_cursor != L.pos_cursor) {
      this->movePrev();
   }
}

// Destructor
List::~List(){
   clear();
   delete frontDummy;
   delete backDummy;
}


// Access functions -----------------------------------------------------------

// isEmpty()
// Returns true if List is empty, otherwise returns false.
bool List::isEmpty(){
   return(num_elements==0);
}

// size()
// Returns the size of List.
int List::size(){
   return(num_elements);
}

// position()
// Returns the position of the cursor in this List. The value returned
// will be in the range 0 to size().
int List::position() {
   return(pos_cursor);
}


// Manipulation procedures ----------------------------------------------------

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront() {
   if (isEmpty()) {
      return;
   }
   pos_cursor = 0;
   beforeCursor = frontDummy;
   afterCursor = frontDummy->next;
}

// moveBack()
// Moves cursor to position size() in this List.
void List::moveBack() {
   if (isEmpty()) {
      return;
   }
   pos_cursor = num_elements;
   beforeCursor = backDummy->prev;
   afterCursor = backDummy;
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<size()
int List::peekNext() {
   if (pos_cursor >= num_elements) {
      cerr << "List Error: calling peekNext with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }
   return(this->afterCursor->data);
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
int List::peekPrev() {
   if (pos_cursor <= 0) {
      cerr << "List Error: calling peekPrev with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }
   return(this->beforeCursor->data);
}

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<size() 
int List::moveNext() {
   if (pos_cursor >= num_elements) {
      cerr << "List Error: calling moveNext with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }
   beforeCursor = afterCursor;
   afterCursor = afterCursor->next;
   pos_cursor++;
   return beforeCursor->data;
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
int List::movePrev() {
   if (pos_cursor <= 0) {
      cerr << "List Error: calling movePrev with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }
   afterCursor = beforeCursor;
   beforeCursor = beforeCursor->prev;
   pos_cursor--;
   return afterCursor->data;
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(int x) {
   Node* N = new Node(x);
   N->prev = this->beforeCursor;
   N->next = this->afterCursor;
   this->beforeCursor->next = N;
   this->afterCursor->prev = N;

   this->afterCursor = N;
   num_elements++;
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(int x) {
   if (x == NIL)
      return;
   Node* N = new Node(x);
   N->prev = this->beforeCursor;
   N->next = this->afterCursor;
   this->beforeCursor->next = N;
   this->afterCursor->prev = N;

   this->beforeCursor = N;
   num_elements++;
   pos_cursor++;
}

// eraseAfter()
// Deletes element after cursor.
// pre: position()<size()
void List::eraseAfter() {
   if( num_elements==0 ){
      cerr << "List Error: calling eraseAfter on an empty List" << endl;
      exit(EXIT_FAILURE);
   }
   if(pos_cursor >= num_elements) {
      cerr << "List Error: calling eraseAfter with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }

   Node* N = afterCursor;
   beforeCursor->next = N->next;
   N->next->prev = beforeCursor;
   afterCursor = N->next;
   num_elements--;
   delete N;
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore() {
   if( num_elements==0 ){
      cerr << "List Error: calling eraseBefore on an empty List" << endl;
      exit(EXIT_FAILURE);
   }
   if(pos_cursor <= 0) {
      cerr << "List Error: calling eraseBefore with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }

   Node* N = beforeCursor;
   afterCursor->prev = N->prev;
   N->prev->next = afterCursor;
   beforeCursor = N->prev;
   num_elements--;
   pos_cursor--;
   delete N;
}

int List::findNext(int x) {
   if(pos_cursor > num_elements || pos_cursor < 0) {
      cerr << "List Error: calling findNext with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }
   if (pos_cursor == num_elements) {
      if (peekPrev() == x)
         return pos_cursor;
      else
         return -1;
   }
   moveNext();
   while (pos_cursor < num_elements) {
      if (peekPrev() == x) {
         return pos_cursor;
      }
      moveNext();
   }
   if(peekPrev() == x) {
      return pos_cursor;
   } else {
      return -1;
   }
}

int List::findPrev(int x) {
   if(pos_cursor > num_elements || pos_cursor < 0) {
      cerr << "List Error: calling findNext with invalid cursor" << endl;
      exit(EXIT_FAILURE);
   }
   if(pos_cursor == 0) {
      if(peekNext() != x)
         return -1;
      else
         return pos_cursor;
   }
   movePrev();
   while(pos_cursor > 0) {
      if (peekNext() == x) {
         return pos_cursor;
      }
      movePrev();
   }
   if(peekNext() == x) {
      return pos_cursor;
   } else {
      return -1;
   }
}

void List::cleanup() {
   if (isEmpty()) {
      cerr << "List Error: calling cleanup on empty list" << endl;
      exit(EXIT_FAILURE);
   }
   Node* N = frontDummy->next;
   Node *before = beforeCursor;
   while(N->next != nullptr) {
      bool one = false;
      moveFront();
      while(pos_cursor < num_elements) {
         if (findNext(N->data) > 0) {
            if (one) {
               if (before == beforeCursor)
                  before = beforeCursor->prev;
               eraseBefore();
            }
            one = true;
         }
      }
      N = N->next;
   }
   moveFront();
   while(beforeCursor != before)
      moveNext();
}

void List::clear() {
   if (isEmpty()) {
      return;
   }
   moveBack();
   while(num_elements>0) {
      eraseBefore();
   }
}

// concat()
// Returns a new List consisting of the elements of this List, followed
// the elements of Q.
List List::concat(const List& L){
   List J;
   Node* N = this->frontDummy->next;
   Node* M = L.frontDummy->next;
   while( N->next!=nullptr ){
      J.insertBefore(N->data);
      N = N->next;
   }
   while( M->next!=nullptr ){
      J.insertBefore(M->data);
      M = M->next;
   }
   J.moveFront();
   return J;
}


// Other Functions ------------------------------------------------------------

// to_string()
// Returns a string representation of List consisting of a space separated 
// list of data values.
string List::to_string(){
   Node* N = nullptr;
   string s = "";

   for(N=frontDummy->next; N->next!=nullptr; N=N->next){
      s += std::to_string(N->data)+" ";
   }
   
   return s;
}

// equals()
// Returns true if and only if this is the same integer sequence as Q.
bool List::equals(const List& L){
   bool eq = false;
   Node* N = nullptr;
   Node* M = nullptr;

   eq = ( this->num_elements == L.num_elements );
   N = this->frontDummy->next;
   M = L.frontDummy->next;
   while( eq && N!=nullptr){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return eq;
}


// Overriden Operators --------------------------------------------------------

// operator<<()
// Inserts string representation of Q into stream.
ostream& operator<< ( ostream& stream,  List& Q ) {
   return stream << Q.List::to_string();
}

// operator==()
// Returns true if and only if A is the same integer sequence as B.
bool operator== (List& A, const List& B){
   return A.List::equals(B);
}

// operator=()
// Overwrites the state of this List with state of Q.
List& List::operator=( const List& L ) {
   if( this != &L ){ // not self assignment
      // make a copy of L
      List temp = L;
      // then swap the copy's fields with fields of this
      std::swap(frontDummy->next, temp.frontDummy->next);
      std::swap(backDummy->prev, temp.backDummy->prev);
      std::swap(num_elements, temp.num_elements);
   }

   // return this with the new data installed
   return *this;

   // the copy, if there is one, is deleted upon return
}