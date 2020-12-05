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

void startQueue(queue *q);
void insert(queue *q, int number);

int main(int argc, char const *argv[]) {
	queue *q = malloc(sizeof(queue));
	startQueue(q);

	insert(q, 1);
	printf("%d %d\n", q->start->number, q->end->number);

	insert(q, 2);
	printf("%d %d\n", q->start->number, q->end->number);
	return 0;
}

void startQueue(queue *q) {
	q->start=NULL;
	q->end=NULL;
}

void insert(queue *q, int number) {
	node *new = malloc(sizeof(node));
	new->number=number;
	new->next=NULL;
	if(q->end != NULL) {
		q->end->next=new;
	}
	else {
		q->start=new;
	}
	q->end=new;
}