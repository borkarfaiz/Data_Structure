/* This is a program for implementing the doubly linked list */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head;

struct Node* GetNewNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
}

void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;

}

void InsertAtEnd(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	struct Node* temp1 = head;
	int i;
	while(temp1->next!=NULL) {
		temp1 = temp1->next;
	}
	temp1->next = newNode;
	newNode->prev = temp1;
}

void Insert(int x, int n) {
	if(n==1) {
		InsertAtHead(x);
		return;
	}
	struct Node* newNode = GetNewNode(x);//nth node;
	struct Node* temp1 = head;
	int i;
	for(i = 0; i<n-2; i++) {
		temp1 = temp1->next; //n-1th node
	}
	struct Node* temp2 = temp1->next; //n+1th Node;
	newNode->prev = temp1;
	newNode->next = temp2;
	temp1->next = newNode;
	temp2->prev = newNode;
}

void Delete(int n) {
	struct Node* temp1 = head;
	if(n==1) {
		head = temp1->next;
		head->prev = NULL;
		free(temp1);
		return;
	}
	int i;
	for(i=0; i<n-2;i++) {
		temp1 = temp1->next; // n-1th node
	}
	struct Node* temp2 = temp1->next; // nth node
	struct Node* temp3 = temp2->next; // n+1th node
	temp1->next = temp3;
	temp3->prev = temp1;
	free(temp2);

}


void Print() {
	struct Node* temp1 = head;
	while(temp1!=NULL) {
		printf("%d ", temp1->data);
		temp1 = temp1->next;
	}
	printf("\n");
}



int main() {
	head = NULL;
	InsertAtHead(5); Print();
	InsertAtEnd(4); Print();
	InsertAtHead(9); Print();
	InsertAtEnd(2); Print();
	Insert(3,2); Print();
	Delete(1); Print();	
	Delete(3); Print();

	getch();
}