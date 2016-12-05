 /* Binary search Tree implementation using linked list */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* root;



struct Node* GetNewNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* insert(struct Node* root, int data) {
	if(root == NULL) {
		root = GetNewNode(data);
	}
	else if(data <= root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}

int search(struct Node* root, int data) {
	if(root == NULL) {
		return -1;
	}
	else if(data == root->data) {
		return 0;
	}
	else if(data <= root->data	) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}


//finding minimum in the list 
int min(struct Node* root) {
	if(root == NULL) return -1;
	if(root->left == NULL) {
		return root->data;
	}
	min(root->left);
}

//it returns the maximum element in the tree
int max(struct Node* root) {
	if(root == NULL) return -1;
	if(root->right == NULL) {
		return root->data;
	}
	max(root->right);
}
void s(struct Node* root, int data) {
	if(search(root,data) == -1) {
		printf("the search fails ");
		return;
	}
	printf("the data is found ");
}


void preorder(struct Node* root) {
	if(root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct Node* root) {
	if(root == NULL) {
		return;
	}
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(struct Node* root) {
	if(root == NULL) {
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int main() {
	root = NULL;
	
	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 7);
	printf("\n preorder_traversal \n"); preorder(root);
	printf("\n inorder_traversal \n"); inorder(root);
	printf("\n postorder_traversal \n"); postorder(root); 
//	traverse(root);
//	s(root, 21);
//	printf("\nthe minmum item in the list is %d ", min(root));
//	printf("\nthe maximum item in the list is %d ", max(root));
	getch();
}