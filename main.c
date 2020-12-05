#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct n {
	int number;
	struct n *next;
} node;

typedef struct c {
	node *start;
	node *end;
} queue;

void printLine();
void startQueue(queue *q);
void insertQueue(queue *q, int number);
void showQueue(queue *q);
bool isEmptyQueue(queue *q);
node * searchQueue(queue *q, int number);
void freeQueue(queue *q);
int removeQueue(queue *q);

int main(int argc, char const *argv[]) {
	queue *q = malloc(sizeof(queue));
	// start test
	startQueue(q);

	// insert test
	insertQueue(q, 1);
	printf("Showing queue:\n");
	showQueue(q);
	insertQueue(q, 2);
	printf("Showing queue again:\n");
	showQueue(q);

	// search test
	node *aux;
	aux = searchQueue(q, 1);

	printf("Searching for number 1:\n");
	if(aux != NULL)
		printf("%d\n", aux->number);

	printf("Removing a number\n");
	int number;
	number = removeQueue(q);
	printf("Removed number: %d\n", number);
	printf("Showing queue again:\n");
	showQueue(q);
	
	// free queue tests
	printf("isEmpty: %d\n", isEmptyQueue(q));
	printf("Cleaning queue\n");
	freeQueue(q);
	printf("isEmpty: %d\n", isEmptyQueue(q));

	return 0;
}

void printLine() {
	printf("----------------------------\n");
}
void startQueue(queue *q) {
	q->start = NULL;
	q->end = NULL;
}

void insertQueue(queue *q, int number) {
	node *new = malloc(sizeof(node));
	new->number = number;
	new->next = NULL;
	if(q->end != NULL) {
		q->end->next = new;
	}
	else {
		q->start = new;
	}
	q->end=new;
}

void showQueue(queue *q) {
	node *aux;
	aux = q->start;
	while(aux != NULL) {
		printf("%d\n", aux->number);
		aux=aux->next;
	}
	printLine();
}

bool isEmptyQueue(queue *q) {
	if (q->end == NULL) 
		return true;
	return false;
}

node * searchQueue(queue *q, int number) {
	node *aux = q->start;
	while (aux != NULL) {
		if(aux-> number == number) {
			return aux;
		}
		aux = aux->next;
	}
	return NULL;
}

void freeQueue(queue *q) {
	node *aux, *aux2;
	aux = q->start;
	while(aux != NULL) {
		aux2 = aux->next;
		aux->next=NULL;
		free(aux);
		aux = aux2;
	}
	q->start=q->end = NULL;
}

int removeQueue(queue *q) {
	node *aux;
	int number;
	if(isEmptyQueue(q))
		return 0;
	aux=q->start;
	q->start=q->start->next;
	aux->next=NULL;
	number=aux->number;
	free(aux);
	if(q->start == NULL)
		q->end = NULL;
	return number;
}