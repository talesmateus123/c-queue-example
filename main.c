#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char const *argv[]) {
	queue *q = malloc(sizeof(queue));
	startQueue(q);

	insertQueue(q, 1);
	showQueue(q);
	insertQueue(q, 2);
	showQueue(q);
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