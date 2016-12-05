/* singly linked list implementation */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head; // global variable - pointer to head

// Creates a new Node and returns pointer to it->
struct Node* GetNewNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//Insert a Node at head
void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	newNode->next = head;
	head = newNode;
}

void Insert(int x,int n) {
	struct Node* newNode = GetNewNode(x);
	
	if(n==1) {
		newNode->next = head;
		head = newNode;
		return;
	}
	struct Node* temp1 = head;
	int i;
	for(i = 0; i < n-2; i++) {
		temp1 = temp1->next;
	}
	newNode->next = temp1->next;
	temp1->next = newNode;
}

void Delete(int n) {
	struct Node* temp1 = head;
	if(n==1) {
		head = temp1->next;
		free(temp1);
		return;
	}
	int i;
	for(i=0; i<n-2; i++) {
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);

}

void Print()  {
	struct Node* temp = head;
	while(temp!=NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main()
{
	head = NULL;
	InsertAtHead(5); Print();
	InsertAtHead(10); Print();
	Insert(6,1); Print();
	Delete(3); Print();
	Insert(7,3); Print();
	Insert(2,2); Print();
	Delete(3); Print();
	
	getch();
}