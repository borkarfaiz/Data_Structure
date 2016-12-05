/* Binary Tree Traversal - level order traversal 
	this is just a function not a full implementation
	in this implementation i am assuming that the tree 
	is already implemented; */

void level_order_traversal(struct Node* root) {
	if(root == NULL) return;
	queue<struct Node*> Q; //here we assume that the queue is already implemented
	Q.push(root);
	while(!Q.IsEmpty()) {
		struct Node* current = Q.front();
		if(current->left!=NULL) {
			Q.push(current->left);
		}
		if(current->right!=NULL) {
			Q.push(current->right);
		}
	}
}