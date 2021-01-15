/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA5
* Shuffle.cpp
* Returns the number of times you have to shuffle a deck of cards of size n
*********************************************************************************/
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

void Shuffle(List* deck);
int main(int argc, char *argv[]) {
	// check if there are too many or too few arguments.
	if (argc != 2) {
		if (argc<2) {
			fprintf(stderr, "Too few arguments.\n");
			exit(EXIT_FAILURE);
		} else {
			fprintf(stderr, "Too many arguments.\n");
			exit(EXIT_FAILURE);
		}
	}

	int cards = stoi(argv[1]);
	int i;

	cout << "deck size       shuffle count" << endl;
	cout << "------------------------------"<<endl;

	if (cards > 0){
		cout << " 1\t\t 1"<<endl;
	}

	for (i = 2; i<=cards; i++) {
		cout << " ";
		cout << i;
		List deck;
		int j;
		for(j = 0; j <i; j++)
			deck.insertBefore(j);

		List original = deck;
		Shuffle(&deck);
		int numShuffle = 1;
		while (original.equals(deck) == false) {
			Shuffle(&deck);
			numShuffle++;
		}
		cout << "\t\t ";
		cout << numShuffle << endl;
	}

	return 0;
}

void Shuffle (List* deck) {
	int j;
	int size = deck->size();
	List deckA;

	deck->moveFront();
	for (j = 0; j<(size/2); j++) {
		deckA.insertBefore(deck->peekNext());
		deck->moveNext();
	}

	List deckB;
	while (j < size) {
		deckB.insertBefore(deck->peekNext());
		j++;
		deck->moveNext();
	}

	deck->clear();
	deckA.moveFront();
	deckB.moveFront();
	while(deckA.position() != deckA.size()){
		deck->insertBefore(deckB.peekNext());
		deck->insertBefore(deckA.peekNext());
		deckA.moveNext();
		deckB.moveNext();
	}
	if (deckB.position() != deckB.size())
		deck->insertBefore(deckB.peekNext());
}