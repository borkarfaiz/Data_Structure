/* circular queue - array based implementation */


#include<stdio.h>
#include<conio.h>

#define N 10
int A[N];
int front = -1, rear = -1;


void Enqeue(int x) {
	if(front== -1 && rear == -1) {
		front = 0;
		rear = 0;
	}
	else if((rear+1)%N == (front+N) % N) {
		printf("The Queue is Full \n");
		return;
	}
	else {
		rear = (rear + 1) % N;
	}
	A[rear] = x;
}

void Dequeue() {
	if(front == -1) {
		printf("The Queue is empty \n");
		return;
	}
	else if (front == rear) {
		front = -1;
		rear = -1;
	}
	else {
		front++;
	}

}

void Print() {
	if(front == -1) {
		printf("The Queue is empty \n");
	}
	else
	{
		printf("Queue: ");
		int i = front;
		while((rear + 1) % N != front % N) {
			printf("%d ", A[i]);
			i = (i+1) % N;
		}
	}
	printf("\n");
}


int main() {
	int i;
	for(i=1; i<=N; i++) {
		Enqeue(i*2); Print();
		}
	Enqeue(5); Print();
	Dequeue(); 	Print();
	Enqeue(54); Print();

	getch();
}

