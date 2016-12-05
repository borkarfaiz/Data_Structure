// stack - Array based implementation.

#include<stdio.h>
#include<conio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x) {
	if(top == MAX_SIZE - 1) {
		printf("Stack Overflow ");
		return;
	}
	A[++top]= x; // A[++top] = x
}

void Pop() {
	if(top == -1) {
		printf("Error: Stack underflow");

	}
	top--;
}

void Top() {
	 printf("%d ",A[top]);
	 printf("\n");
}

void Print() {
	int i;
	printf("Stack: ");
	for(i=0; i<=top; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}


int main() {
	Push(2); Print();
	Push(5); Print();
	Top(); Print();
	Pop(); Print();
	Push(4); Print();

	getch();
}