/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA4
* GraphTest.c
* Test file for Graph ADT
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "List.h"
#include "Graph.h"

int main(int argc, char* argv[]) {
	printf("Running Tests for Graph ADT...\n");

	// Constructor Tests
	printf("Constructor Tests: \n");
	Graph G = newGraph(6);
	printf("\tCreated without Errors\n");
	if (getOrder(G) == 6) {
		printf("\tOrder initialise: PASSED\n");
	} else {
		printf("\tOrder initialise: FAILED\n");
	}
	if (getSize(G) == 0) {
		printf("\tSize initialise: PASSED\n");
	} else {
		printf("\tSize initialise: FAILED\n");
	}
	
	int i;
	int checkParent = 1;	// true
	int checkDiscover = 1;
	int checkFinish = 1;
	for (i = 1; i < getOrder(G)+1;i++) {
		if (getParent(G, i) != NIL) {
			checkParent = 0;
		}
		if (getDiscover(G, i) != UNDEF) {
			checkDiscover = 0;
		}
		if (getFinish(G, i) != UNDEF) {
			checkFinish = 0;
		}
	}

	if (checkParent == 1) {
		printf("\tParent Array initialise: PASSED\n");
	} else {
		printf("\tParent Array initialise: FAILED\n");
	}
	if (checkDiscover == 1) {
		printf("\tDiscover Array initialise: PASSED\n");
	} else {
		printf("\tDiscover Array initialise: FAILED\n");
	}
	if (checkFinish == 1) {
		printf("\tFinish Array initialise: PASSED\n");
	} else {
		printf("\tFinish Array initialise: FAILED\n");
	}

	printf("\nAccess Functions were tested with the Constructor\n");
	printf("\nAdd Edge Tests:\n");
	printf("Graph G:\n");
	addEdge(G, 2, 4);
	addEdge(G, 1, 3);
	addEdge(G, 1, 2);
	addEdge(G, 4, 5);
	addEdge(G, 3, 4);
	addEdge(G, 2, 5);
	addEdge(G, 2, 6);
	addEdge(G, 4, 5);
	addEdge(G, 5, 6);
	printGraph(stdout, G);
	printf("\nSize test: ");
	if (getSize(G) == 8) {
		printf("PASSED\n");
	} else {
		printf("FAILED | size = %d\n", getSize(G));
	}

	printf("\nAdd Arc Tests:\n");
	addArc(G, 2, 3);
	printGraph(stdout, G);
	printf("\nSize test 1: ");
	if (getSize(G) == 9) {
		printf("PASSED\n");
	} else {
		printf("FAILED | size = %d\n", getSize(G));
	}

	Graph F = newGraph(8);
	addArc(F, 1, 2);
	addArc(F, 2, 3);
	addArc(F, 2, 5);
	addArc(F, 2, 6);
	addArc(F, 3, 4);
	addArc(F, 3, 7);
	addArc(F, 4, 3);
	addArc(F, 4, 8);
	addArc(F, 5, 1);
	addArc(F, 5, 6);
	addArc(F, 6, 7);
	addArc(F, 7, 6);
	addArc(F, 7, 8);
	addArc(F, 8, 8);

	printGraph(stdout, F);
	printf("\nSize test 2: ");
	if (getSize(F) == 14) {
		printf("PASSED\n");
	} else {
		printf("FAILED | size = %d\n", getSize(F));
	}

	// copy graph tests
	printf("Copy Tests:\n");
	Graph FCopy = copyGraph(F);

	printf("\tCopy test with F: ");
	if (compareGraph(FCopy, F)) {
		printf("PASSED\n");
	} else {
		printf("FAILED\n");
	}

	freeGraph(&FCopy);

	// transpose test
	printf("Transpose Tests:\n");
	Graph FT = transpose(F);
	Graph FTRanspose = newGraph(8);
	addArc(FTRanspose, 2, 1);
	addArc(FTRanspose, 3, 2);
	addArc(FTRanspose, 5, 2);
	addArc(FTRanspose, 6, 2);
	addArc(FTRanspose, 4, 3);
	addArc(FTRanspose, 7, 3);
	addArc(FTRanspose, 3, 4);
	addArc(FTRanspose, 8, 4);
	addArc(FTRanspose, 1, 5);
	addArc(FTRanspose, 6, 5);
	addArc(FTRanspose, 7, 6);
	addArc(FTRanspose, 6, 7);
	addArc(FTRanspose, 8, 7);
	addArc(FTRanspose, 8, 8);

	printf("\tTranspose test with F: ");
	if (compareGraph(FT, FTRanspose) == 2) {
		printf("PASSED\n");
	} else {
		printf("FAILED: %d\n\tFT:\n", compareGraph(FT, FTRanspose));
		printGraph(stdout, FT);
		printf("\nFTranspose:\n");
		printGraph(stdout, FTRanspose);
		printf("\n");
	}

	freeGraph(&FTRanspose);

	// DFS tests
	printf("DFS Tests:\n");
	List S = newList();
	for (i = 1; i <= getOrder(F); i++) {
		append(S, i);
	}
	DFS(F, S);
	int parentTest[] = {0, 1, 2, 3, 2, 7, 3, 4};
	int discoverTest[] = {1, 2, 3, 4, 13, 9, 8, 5};
	int finishTest[] = {16, 15, 12, 7, 14, 10, 11, 6};

	printf("\tDFS Test with F: ");
	int pass = 1;
	for (i = 1; i <= getOrder(F); i++) {
		if (getParent(F, i) != parentTest[i-1]) {
			printf("FAILED parentTest at index %d\n", i);
			pass = 0;
		}
		if (getDiscover(F, i) != discoverTest[i-1]) {
			printf("FAILED discoverTest at index %d\n", i);
			pass = 0;
		}
		if (getFinish(F, i) != finishTest[i-1]) {
			printf("FAILED finishTest at index %d\n", i);
			pass = 0;
		}
	}

	if (pass) {
		printf("PASSED\n");
	}
	printf("\tReturn List: ");
	printList(stdout, S);
	printf("\n");

	// finding strongly connected components
	printf("Finding strongly connected components: \n");
	DFS(FT, S);
	printf("\tReturned parent list: ");
	int parents[getOrder(FT)+1];
	int numroots = 0;
	for (i = 1; i<= getOrder(FT); i++) {
		printf("%d ", getParent(FT, i));
		parents[i] = getParent(FT, i);
		if (parents[i] == 0) {
			numroots++;
		}
	}
	int roots[numroots];
	printf("\n\tRoots: ");
	int j = 0;
	for (i = 1; i<= getOrder(FT); i++) {
		if (parents[i] == 0) {
			roots[j] = i;
			printf("%d ", roots[j]);
			j++;
		}
	}
	List trees[numroots];
	for (i = 0; i<numroots; i++) {
		trees[i] = newList();
		append(trees[i], roots[i]);
		moveFront(trees[i]);
		while(indexL(trees[i]) >= 0) {
			int x = get(trees[i]);
			for (j = 1; j <=getOrder(FT); j++) {
				if (parents[j] == x) {
					append(trees[i], j);
				}
			}
			moveNext(trees[i]);
		}
		printf("\n\tComponent %d: ", i+1);
		printList(stdout, trees[i]);
	}

	// Destructor Tests
	printf("\nDestructor Tests: \n");
	freeGraph(&FT);
	freeGraph(&G);
	freeGraph(&F);
	freeList(&S);
	for(i = 0; i < numroots; i++) {
		freeList(&trees[i]);
	}
	printf("\tFreed without Errors\n");

	return 0;

}