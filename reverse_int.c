#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

typedef struct Stack {
	Node *head;
	Node *tail;
} Stack;

Stack createList(){
	Stack s;
	s.head = NULL;
	s.tail = NULL;
	return s;
}

Node *createNode(int data){
	Node *n = malloc(sizeof(Node));
	n->val = data;
	n->next = NULL;
	return n;
}

void enqueue(Stack *s, int data){
	Node *newNode = createNode(data);
	if (!(s->head)){
		s->head = s->tail = newNode;
	} else {
		s->tail->next = newNode;
		s->tail = s->tail->next;
	}
	printf("head %i\ttail %i\n", s->head->val, s->tail->val);
}

void dequeue(Stack *s){
	Node *temp = s->head;
	s->head = s->head->next;
	printf("dequeued %i\n", temp->val);
	free(temp);
}

void printList(Node *head){
	if (head){
		printf("%i->", head->val);
		printList(head->next);
	}
}

void clearList(Stack *s){
	if (s->head){
		dequeue(s);
		clearList(s);
	}
}

size_t getSize(Stack s){
	int count;
	Node *node = s.head;
	for ( ; node; node = node->next, count++);
	return count;
}

int getReverse(int input){
	const int BASE = 10;
	Stack s = createList();
	while (input){
		enqueue(&s, input % BASE);
		input /= BASE;
	}
	printList(s.tail);
	Node *n = s.head;
	int placeVal = 1;
	int num10s = getSize(s);
	printf("num10s: %i\n", num10s);
	int num = 0;

	for (int i = 1; i < num10s; i++){
		printList(s.head);
		printf("%i \n", i);
		placeVal *= BASE;	
	}
	for ( ; s.head; dequeue(&s)){
		num += s.head->val * placeVal;	
		placeVal /= BASE;
	}
	printf("num %i\n", num);
	return num;
}

int main(){
	Stack s = createList();
	getReverse(12345);
	getReverse(624364);

}
