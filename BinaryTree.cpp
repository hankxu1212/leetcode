#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int indata) {
		data = indata;
		left = NULL;
		right = NULL;
	}
};

void insertNode(Node root, int indata) {
	if (indata > root.data) {
		if (root.right == NULL) {
			Node n(indata);
			root.right = &n;
		}
		else
			insertNode(*root.right, indata);
	}
	else if (indata < root.data) {
		if (root.left == NULL) {
			Node n(indata);
			root.left = &n;
		}
		else
			insertNode(*root.left, indata);
	}
}

void printTree(Node root) {
	if (root.left != NULL)
		printTree(*root.left);
	cout << root.data;
	if (root.right != NULL)
		printTree(*root.right);
}

int main()
{
	Node tree(8);
	insertNode(tree, 9);
	insertNode(tree, 10);
	insertNode(tree, 1);
	insertNode(tree, 12);
	printTree(tree);
}