#ifndef BinaryTree_H
#define BinaryTree_H

#include "Traversal.h"

typedef struct Node Node;


struct Node{
	Node *left;
	Node *right;
	int data;
	NodeState state;
};


void binaryTreeTraversalInOder(Node *root);
void printLinear(Node *node);
void binaryTreePrintInOrder(Node *node);
int checkleftnode(Node *currentNode);
int checkrightnode(Node *currentNode);
void printNodeState(Node *currentNode);

#endif // BinaryTree_H
