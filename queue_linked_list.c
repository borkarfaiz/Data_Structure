/* Queue - Link list based implementation */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;


void Enqueue(int x) {
	struct Node* newNode =(struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	if(front == NULL) {
		front = newNode;
		rear = newNode;
		return;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
}

void Dequeue() {
	struct Node* temp1 = front;
	if(front == NULL) {
		printf("The Queue is already empty");
		return;
	}
	front = temp1->next;
	free(temp1);
}

void Print() {
	struct Node* temp1 = front;
	if(temp1 == NULL) {
		printf("The Queue is Empty \n");
		return;
	}
	printf("Queue: ");
	while(temp1 != NULL) {
		printf("%d ", temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}

int main() {
	Enqueue(5); Print();
	Enqueue(6); Print();
	Enqueue(7); Print();
	Dequeue(); Print();
	getch();
}