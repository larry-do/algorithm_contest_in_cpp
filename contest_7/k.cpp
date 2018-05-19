#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node	*left, *right;
};
Node* newNode(int data){
	Node *node = new Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
Node* insertNode(Node* node, int data){
	if(node == NULL) return newNode(data);
	if(data < node->data) node->left = insertNode(node->left, data);
	if(data > node->data) node->right = insertNode(node->right, data);
	return node;
}
Node* getMinValue(Node* node){
	Node* tmp = node;
	while(tmp->left != NULL){
		tmp = tmp->left;
	}
	return tmp;
}
Node* deleteNode(Node *node, int key){
	if(node == NULL) return node;
	if(key < node->data) node->left = deleteNode(node->left, key);
	else if(key > node->data) node->right = deleteNode(node->right, key);
	else{
		if(node->left == NULL){
			Node *tmp = node->right;
			delete[] node;
			return tmp;
		}
		if(node->right == NULL){
			Node *tmp = node->left;
			delete[] node;
			return tmp;
		}
		Node *tmp = getMinValue(node->right);
		node->data = tmp->data;
		node->right = deleteNode(node->right, tmp->data);
	}
	return node;
}
Node* binarySearchTree(Node *node, int key){
	if(node == NULL || key == node->data) return node;
	if(key < node->data) return binarySearchTree(node->left, key);
	return binarySearchTree(node->right, key);
}
void printInOrder(Node *node){
	if(node == NULL) return;
	printInOrder(node->left);
	cout<<node->data<<" ";
	printInOrder(node->right);
}
void printPostOrder(Node *node){
	if(node == NULL) return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	cout<<node->data<<" ";
}
void printPreOrder(Node *node){
	if(node == NULL) return;
	cout<<node->data<<" ";
	printPreOrder(node->left);
	printPreOrder(node->right);
}
int main(){
	Node *node = NULL;
	int select, key;
	while(cin>>select){
		if(select == 1){
			cin>>key;
			node = insertNode(node, key);
		}
		else if(select == 2){
			cin>>key;
			node = deleteNode(node, key);
		}		
		else if(select == 3){
			printPreOrder(node);
			cout<<endl;
		}
		else if(select == 4) {
			printInOrder(node);
			cout<<endl;
		}
		else {
			printPostOrder(node);
			cout<<endl;
		}
	}
	return 0;
}
