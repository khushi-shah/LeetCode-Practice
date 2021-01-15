/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA5
* ListTest.cpp
* Test file for List ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main(){

   cout << "Running List Tests:" << endl;

   // Constructor Tests
   cout << "Constructor Tests" << endl;
   List* L = new List();
   cout << "\tCreated Successfully" << endl;

   if (L->isEmpty())
   	cout << "\tCreated Empty" << endl;
   if (L->size() == 0)
   	cout << "\tSize = 0" << endl;
   if (L->position() == 0)
   	cout << "\tPos = 0" << endl;

   // InsertBefore Tests
   cout << "insertBefore Tests" << endl;
   int i;
   for (i = 0; i<7; i++) {
   	L->insertBefore(i);
   }
   cout << "\t" + L->to_string() << endl;
   if (L->position() == 7 && L->size() == 7)
   	cout << "\tSize and position checked" << endl;

   // InsertAfter Tests
   cout << "insertAfter Tests" << endl;
   for (i = 10; i > 6; i--)
   	L->insertAfter(i);
   cout << "\t" + L->to_string() << endl;
   if (L->position() == 7 && L->size() == 11)
   	cout << "\tSize and position checked" << endl;


   bool peekPrevTest = true;
   bool peekNextTest = true;
   // moveFront Test
   cout << "moveFront Tests" << endl;
   L->moveFront();
   if (L->position() == 0)
   	cout << "\tPASSED" << endl;
   else {
   	cout << "\tFAILED: ";
   	cout << L->position() << endl;
   }

   if (L->peekNext() != 0)
   	peekNextTest = false;

   // moveBack Test
   L->moveBack();
   cout << "moveBack Tests" << endl;
   if (L->position() == L->size())
   	cout << "\tPASSED" << endl;

   if (L->peekPrev() != 10)
   	peekPrevTest = false;

   // movePrev Test
   cout << "movePrev Tests" << endl;
   for (i = 0; i<8; i++)
   	L->movePrev();
   if (L->position() == 3)
   	cout << "\tPASSED" << endl;

   if (L->peekNext() != 3)
   	peekNextTest = false;
   if (L->peekPrev() != 2)
   	peekPrevTest = false;

   // moveNext Test
   cout << "moveNext Tests" << endl;
   for (i = 0; i<5; i++)
   	L->moveNext();
   if (L->position() == 8)
   	cout << "\tPASSED" << endl;

   if (L->peekNext() != 8)
   	peekNextTest = false;
   if (L->peekPrev() != 7)
   	peekPrevTest = false;

   // peekPrevTest Results
   cout << "peekPrev Tests" << endl;
   if (peekPrevTest)
   	cout << "\tPASSED" << endl;
   else
   	cout << "\tFAILED" << endl;

   // peekNextTest Results
   cout << "peekNext Tests" << endl;
   if (peekNextTest)
   	cout << "\tPASSED" << endl;
   else
   	cout << "\tFAILED" << endl;

   // copy constructor tests
   cout << "Copy Constructor Tests" << endl;
   List* M = new List(*L);
   cout << "\t" + M->to_string() << endl;
   if (M->equals(*L))
   	cout << "\tPASSED" << endl;

   //eraseBefore Tests
   cout << "eraseBefore Tests" << endl;
   for (i = 0; i < 4; i++) {
   	M->eraseBefore();
   }
   cout << "\t" + M->to_string() << endl;
   if (M->position() == 4)
   	cout << "\tPosition: PASSED" << endl;
   else {
   	cout << "\tFAILED: ";
   	cout << M->position() << endl;
   }
   if(M->peekNext() == 8)
   	cout << "\tNext: PASSED" <<endl;
   else {
   	cout << "\tFAILED: ";
   	cout << M->peekNext() << endl;
   }
   if (M->peekPrev() == 3)
   	cout << "\tPrev: PASSED" <<endl;
   else {
   	cout << "\tFAILED: ";
   	cout << M->peekPrev() << endl;
   }

   //eraseAfter Tests
   cout << "eraseAfter Tests" << endl;
   M->movePrev(); M->movePrev();
   for (i = 0; i<4 ;i++){
   	M->eraseAfter();
   }
   cout << "\t" + M->to_string() << endl;
   if (M->position() == 2)
   	cout << "\tPosition: PASSED" << endl;
   else {
   	cout << "\tFAILED: ";
   	cout << M->position() << endl;
   }
   if(M->peekNext() == 10)
   	cout << "\tNext: PASSED" <<endl;
   else {
   	cout << "\tFAILED: ";
   	cout << M->peekNext() << endl;
   }
   if (M->peekPrev() == 1)
   	cout << "\tPrev: PASSED" <<endl;
   else {
   	cout << "\tFAILED: ";
   	cout << M->peekPrev() << endl;
   }

   //findNext Test
   cout << "findNext Tests" << endl;
   M->moveNext();
   M->insertBefore(0); M->insertBefore(2); M->insertBefore(1);
   M->insertBefore(10); M->insertBefore(1); M->insertBefore(10);
   M->insertBefore(2); M->insertBefore(0); M->insertBefore(3);
   M->insertBefore(3);

   M->moveFront();
   cout << "\tCursor pos. after 0: ";  // 1, 4, 11
   while (M->position() < M->size()) {
   	cout << M->findNext(0);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveFront();
   cout << "\tCursor pos. after 1: ";	// 2, 6, 8
   while (M->position() < M->size()) {
   	cout << M->findNext(1);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveFront();
   cout << "\tCursor pos. after 10: ";	// 3, 7, 9
   while (M->position() < M->size()) {
   	cout << M->findNext(10);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveFront();
   cout << "\tCursor pos. after 2: ";	// 5, 10
   while (M->position() < M->size()) {
   	cout << M->findNext(2);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveFront();
   cout << "\tCursor pos. after 3: ";	// 12, 13
   while (M->position() < M->size()) {
   	cout << M->findNext(3);
   	cout << " ";
   }
   cout << "" << endl;

   //findPrev Test
   cout << "findPrev Tests" << endl;

   M->moveBack();
   cout << "\tCursor pos. after 0: ";  // 1, 4, 11
   while (M->position() > 0) {
   	cout << M->findPrev(0);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveBack();
   cout << "\tCursor pos. after 1: ";	// 2, 6, 8
   while (M->position() > 0) {
   	cout << M->findPrev(1);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveBack();
   cout << "\tCursor pos. after 10: ";	// 3, 7, 9
   while (M->position() > 0) {
   	cout << M->findPrev(10);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveBack();
   cout << "\tCursor pos. after 2: ";	// 5, 10
   while (M->position() > 0) {
   	cout << M->findPrev(2);
   	cout << " ";
   }
   cout << "" << endl;

   M->moveBack();
   cout << "\tCursor pos. after 3: ";	// 12, 13
   while (M->position() > 0) {
   	cout << M->findPrev(3);
   	cout << " ";
   }
   cout << "" << endl;

   // cleanup Tests
   for (i = 0; i < 7; i++)
   	M->moveNext();
   cout << "cleanup Tests" << endl;
   cout << "\tBefore: " + M->to_string() << endl;
   cout << "\tCursor Before: ";
   cout << M->position() << endl;
   M->cleanup();
   cout << "\tAfter: " + M->to_string() << endl;
   cout << "\tCursor After: ";
   cout << M->position() << endl;

   //concat Tests
   cout << "concat Tests" << endl;
   List LM = L->concat(*M);
   cout << "\t" + LM.to_string() << endl;

   // Operator Tests
   cout << "Operator Tests" << endl;
   List MCopy = *M;
   if (MCopy.equals(*M))
   	cout << "\tCopy Operator: PASSED" << endl;
   if (MCopy == *M)
   	cout << "\tEquals Operator: PASSED" << endl;

   //clear Tests
   cout << "clear Tests" << endl;
   L->clear();
   M->clear();
   LM.clear();

   if (L->isEmpty())
   	cout << "\tMade Empty" << endl;
   if (L->size() == 0)
   	cout << "\tSize = 0" << endl;
   if (L->position() == 0)
   	cout << "\tPos = 0" << endl;

   cout << "\t------------" << endl;  

   if (M->isEmpty())
   	cout << "\tCreated Empty" << endl;
   if (M->size() == 0)
   	cout << "\tSize = 0" << endl;
   if (M->position() == 0)
   	cout << "\tPos = 0" << endl;

   cout << "\t------------" << endl; 

   if (LM.isEmpty())
   	cout << "\tCreated Empty" << endl;
   if (LM.size() == 0)
   	cout << "\tSize = 0" << endl;
   if (LM.position() == 0)
   	cout << "\tPos = 0" << endl;

   // Destructor Tests
   cout << "Destructor Tests" << endl;
   delete L;
   delete M;
   cout << "\tFreed Successfully" << endl;

   return(0);
}