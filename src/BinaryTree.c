#include "BinaryTree.h"
#include "Stack.h"
#include "Traversal.h"
#include <stdio.h>

void changeNodeState(Node *currentNode)
{
	switch(currentNode->state)
	{
		case ENTERED_NODE:
			currentNode->state = VISIT_LEFT_NODE;
			break;
		case VISIT_LEFT_NODE:
			currentNode->state = VISIT_RIGHT_NODE;
			break;
		case VISIT_RIGHT_NODE:
			currentNode->state = VISITED_BOTH_NODE;
			break;
		case UNKNOWN_NODE_STATE:
			currentNode->state = ENTERED_NODE;
			break;
	}
}




void printNodeState(Node *currentNode)
{
	if( currentNode->state == VISIT_LEFT_NODE)
		printf("Status of Node %d changed to VISIT_LEFT_NODE\n", currentNode->data);
	else if( currentNode->state == VISIT_RIGHT_NODE)
		printf("Status of Node %d changed to VISIT_RIGHT_NODE\n", currentNode->data);
	else if( currentNode->state == ENTERED_NODE)
		printf("Status of Node %d changed to ENTERED_NODE\n", currentNode->data);
	else if( currentNode->state == VISITED_BOTH_NODE)
		printf("Status of Node %d changed to VISITED_BOTH_NODE\n", currentNode->data);
}



int checkleftnode(Node *currentNode)
{
	if (currentNode->left == NULL)
		return 0;
	else
		return 1;
}



int checkrightnode(Node *currentNode)
{
	if (currentNode->right == NULL)
		return 0;
	else
		return 1;
}




void binaryTreeTraversalInOder(Node *root)
{
	Node *currentNode = root;
	int node_indicator;  //0 indicate empty, 1 indicate filled
	Stack *stack = stackNew();
	printf("created a stack\n");
	
	while(currentNode != NULL)
	{
		if(currentNode->state == VISIT_LEFT_NODE)
		{
			display(currentNode->data);
			printf("CurrentNode is %d \n", currentNode->data);
			changeNodeState(currentNode);
			printNodeState(currentNode);
		}
		else if(currentNode->state == UNKNOWN_NODE_STATE)
		{
			changeNodeState(currentNode);
			printNodeState(currentNode);
		}
		else if( currentNode->state == ENTERED_NODE)
		{
			node_indicator = checkleftnode(currentNode);
			changeNodeState(currentNode);		//visit to left
			printNodeState(currentNode);
			if(node_indicator != 0)
			{
				stackPush(stack , currentNode);
				printf("Pushed Stack Node %d\n", currentNode->data);
				currentNode = currentNode->left;
			}
		}
		else if(currentNode->state == VISIT_RIGHT_NODE)
		{
			node_indicator = checkrightnode(currentNode);
			if(node_indicator == 1)
			{
				if (currentNode->right->state != VISITED_BOTH_NODE)
				{
					stackPush(stack , currentNode);
					printf("Pushed Stack Node %d\n", currentNode->data);
					currentNode = currentNode->right;
				}
				else
				{
					changeNodeState(currentNode);		//visited both node
					printNodeState(currentNode);
				}
			}
			else
			{
				changeNodeState(currentNode);		//visited both node
				printNodeState(currentNode);
			}
		}
		else if(currentNode->state == VISITED_BOTH_NODE)
		{
			currentNode = stackPop(stack);
			printf("Popped stack\n");
		}
	}
	stackDel(stack);
	printf("deleted a stack\n");
	
	// if( currentNode->left == NULL)
	// {
		// changeNodeState(currentNode);				//case 1
		// currentNode->state = ENTERED_NODE;
		// printf("Changed state to ENTERED_NODE\n");
		// display(currentNode->data);
		// printf("CurrentNode is %d \n", currentNode->data);
		
		// if( currentNode->right != NULL)		// case 4
		// {
			// stackPush(stack , currentNode);
			// printf("Pushed Stack\n");
			// currentNode = currentNode->right;
			// display(currentNode->data);
			// printf("CurrentNode is %d \n", currentNode->data);
			// currentNode = stackPop(stack);
			// printf("Popped stack\n");	
		// }
		// currentNode = stackPop(stack);
		// printf("Popped stack\n");
		// printf("Address : %p \n" , currentNode);
	// }
	// else
	// {
		// currentNode->state = ENTERED_NODE;
		// printf("Changed state to ENTERED_NODE\n");
		// stackPush(stack , currentNode);
		// printf("Pushed Stack\n");
		// currentNode = currentNode->left;
		
		// display(currentNode->data);
		// printf("CurrentNode is %d \n", currentNode->data);
		// currentNode = stackPop(stack); 
		// printf("Popped stack\n");
		// changeNodeState(currentNode);
		// printf("Changed state to VISITED_LEFT_NODE\n");
		
		// if( currentNode->state == VISITED_LEFT_NODE	&& currentNode->right == NULL) 		//case 2
		// {
			// display(currentNode->data);
			// printf("CurrentNode is %d \n", currentNode->data);
			// currentNode = stackPop(stack);
			// printf("Popped stack\n");
			// printf("Address : %p \n" , currentNode);
		// }
		// else 
		// {
			// display(currentNode->data);								//case 3
			// printf("CurrentNode is %d \n", currentNode->data);
			// stackPush(stack , currentNode);
			// printf("Pushed Stack\n");
			// currentNode = currentNode->right;
			// display(currentNode->data);
			// printf("CurrentNode is %d \n", currentNode->data);
			// currentNode = stackPop(stack);
			// printf("Popped stack\n");
			// changeNodeState(currentNode);
			// printf("Changed state to VISITED_RIGHT_NODE\n");
			// currentNode = stackPop(stack);
			// printf("Popped stack\n");
			// printf("Address : %p \n" , currentNode);
		// }
			
	// }
	
	// stackDel(stack);
	// printf("deleted a stack\n");
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


