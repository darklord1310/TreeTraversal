#include "BinaryTree.h"
#include "Stack.h"
#include "Traversal.h"
#include <stdio.h>

void changeNodeState(Node *currentNode)
{
	switch(currentNode->state)
	{
		case ENTERED_NODE:
			currentNode->state = VISITED_LEFT_NODE;
			break;
		case VISITED_LEFT_NODE:
			currentNode->state = VISITED_RIGHT_NODE;
			break;
		case UNKNOWN_NODE_STATE:
			currentNode->state = ENTERED_NODE;
			break;
	}
}

void binaryTreeTraversalInOder(Node *root)
{
	Node *currentNode = root;
	
	Stack *stack = stackNew();
	printf("created a stack\n");
	
	
	changeNodeState(currentNode);	
	// stackPush();
	// checkleftnode();
	// display();
	// checkrightnode();
	
	
	if( currentNode->left == NULL)
	{
		changeNodeState(currentNode);				//case 1
		currentNode->state = ENTERED_NODE;
		printf("Changed state to ENTERED_NODE\n");
		display(currentNode->data);
		printf("CurrentNode is %d \n", currentNode->data);
		
		if( currentNode->right != NULL)		// case 4
		{
			stackPush(stack , currentNode);
			printf("Pushed Stack\n");
			currentNode = currentNode->right;
			display(currentNode->data);
			printf("CurrentNode is %d \n", currentNode->data);
			currentNode = stackPop(stack);
			printf("Popped stack\n");	
		}
		currentNode = stackPop(stack);
		printf("Popped stack\n");
		printf("Address : %p \n" , currentNode);
	}
	else
	{
		currentNode->state = ENTERED_NODE;
		printf("Changed state to ENTERED_NODE\n");
		stackPush(stack , currentNode);
		printf("Pushed Stack\n");
		currentNode = currentNode->left;
		
		display(currentNode->data);
		printf("CurrentNode is %d \n", currentNode->data);
		currentNode = stackPop(stack); 
		printf("Popped stack\n");
		changeNodeState(currentNode);
		printf("Changed state to VISITED_LEFT_NODE\n");
		
		if( currentNode->state == VISITED_LEFT_NODE	&& currentNode->right == NULL) 		//case 2
		{
			display(currentNode->data);
			printf("CurrentNode is %d \n", currentNode->data);
			currentNode = stackPop(stack);
			printf("Popped stack\n");
			printf("Address : %p \n" , currentNode);
		}
		else 
		{
			display(currentNode->data);								//case 3
			printf("CurrentNode is %d \n", currentNode->data);
			stackPush(stack , currentNode);
			printf("Pushed Stack\n");
			currentNode = currentNode->right;
			display(currentNode->data);
			printf("CurrentNode is %d \n", currentNode->data);
			currentNode = stackPop(stack);
			printf("Popped stack\n");
			changeNodeState(currentNode);
			printf("Changed state to VISITED_RIGHT_NODE\n");
			currentNode = stackPop(stack);
			printf("Popped stack\n");
			printf("Address : %p \n" , currentNode);
		}
			
	}
	
	stackDel(stack);
	printf("deleted a stack\n");
}



void printLinear(Node *node)
{
	if(node != NULL)
	{
		printLinear(node->left);
		printf("Node : %d\n", node->data);
	}
}



void binaryTreePrintInOrder(Node *node)
{
	if(node != NULL)
	{
		binaryTreePrintInOrder(node->left);
		printf("Node : %d\n", node->data);
		binaryTreePrintInOrder(node->right);
	}

}


