/*********************************************************************************
* Khushi Shah, khkshah
* 2020 Fall CSE 101 PA4
* FindComponents.c
* Prints the Graph from the infile and all of it's strongly connecoted components
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "Graph.h"
#include "List.h"
#include "string.h"

int getNum(FILE *in);
int main(int argc, char* argv[]) {

	// check if there are too many or too few arguments.
	if (argc != 3) {
		if (argc<3) {
			fprintf(stderr, "Too few arguments.\n");
			exit(EXIT_FAILURE);
		} else {
			fprintf(stderr, "Too many arguments.\n");
			exit(EXIT_FAILURE);
		}
	}

	// open the files
	FILE* in = fopen(argv[1], "r");		// the input file is only to be read
	FILE* out = fopen(argv[2], "w");	// the output file is only to be written

	//Create the Graph
	int numVertex = getNum(in);
	Graph A = newGraph(numVertex);
	//add Edges
	char c = fgetc(in); // newline
	c = getNum(in); // first vertex
	while(c != 0) {
		int u = c;
		fgetc(in); // the whitespace in the middle
		int v = getNum(in);
		addArc(A, u, v);
		fgetc(in); 	// newline
		c = getNum(in);
	}
	printf("Adjacency list representation of G:\n");
	fprintf(out, "Adjacency list representation of G:\n");
	printGraph(stdout, A);
	printGraph(out, A);
	int i = 1;
	List S = newList();
	for (i = 1; i <= getOrder(A); i++) {
		append(S, i);
	}
	DFS(A, S);
	List saved = copyList(S);
	Graph AT = transpose(A);
	DFS(AT, S);
	int numroots = 0;
	for (i = 1; i<= getOrder(AT); i++) {
		if (getParent(AT, i) == 0) {
			numroots++;
		}
	}
	int roots[numroots];
	int j = 0;
	moveFront(saved);
	while(index(saved) >= 0) {
		if (getParent(AT, get(saved)) == 0) {
			roots[j] = get(saved);
			j++;
		}
		moveNext(saved);
	}
	printf("\n\nG contains %d strongly connected components:", numroots);
	fprintf(out, "\n\nG contains %d strongly connected components:", numroots);
	List trees[numroots];
	for (i = 0; i<numroots; i++) {
		trees[i] = newList();
		append(trees[i], roots[i]);
		moveFront(trees[i]);
		while(index(trees[i]) >= 0) {
			int x = get(trees[i]);
			for (j = 1; j <=getOrder(AT); j++) {
				if (getParent(AT, j) == x) {
					append(trees[i], j);
				}
			}
			moveNext(trees[i]);
		}
		printf("\nComponent %d: ", i+1);
		printList(stdout, trees[i]);
		fprintf(out, "\nComponent %d: ", i+1);
		printList(out, trees[i]);
	}

	freeGraph(&A);
	freeGraph(&AT);
	freeList(&S);
	freeList(&saved);
	for(i = 0; i < numroots; i++) {
		freeList(&trees[i]);
	}

	fclose(in);
	fclose(out);

	return 0;

}

int getNum(FILE *in) {
	long int startPos = ftell(in);

	char c = fgetc(in);
	int digits = 0;
	while ((c!=32) && (c!='\n')) {
		digits++;
		c = fgetc(in);
	}

	fseek(in, startPos, SEEK_SET);
	char s[digits];
	fgets(s, digits+1, in);
	int num = (int)strtol(s, NULL, 10);
	return num;
}