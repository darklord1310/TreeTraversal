#include "unity.h"
#include "BinaryTree.h"
#include "mock_Print.h"
#include "mock_Stack.h"
#include "Traversal.h"


void setUp(void)
{
}

void tearDown(void)
{
}


/**
 *    10
 *   /  \
 *  -   -
 */
void test_binary_tree_with_1_node(void)
{
	Node root = {NULL, NULL , 10, UNKNOWN_NODE_STATE};
	Stack stack;
	
	printf("---------------------------------------------------------------------\n");
	
	//mock
	stackNew_ExpectAndReturn(&stack);
	printf("Starts test_binary_tree_with_1_node\n");
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	//Code
	binaryTreeTraversalInOder(&root);
	
}


/**
 *    10
 *   /  \
 *  5   -
 */
void test_binary_tree_with_2_nodes_parent_and_left_child(void)
{
	Node leftChild = {NULL, NULL , 5, UNKNOWN_NODE_STATE};
	Node root = {&leftChild, NULL , 10, UNKNOWN_NODE_STATE};
	Stack stack;
	
	printf("---------------------------------------------------------------------\n");
	
	//mock
	printf("Starts test_binary_tree_with_2_nodes_parent_and_left_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack , &root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack, &root);
	display_Expect(10);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	//Code
	binaryTreeTraversalInOder(&root);
	
}



/**
 *    10
 *   /  \
 *  5   20
 */
void test_binary_tree_with_3_nodes_parent_left_child_and_right_child(void)
{
	Node leftChild = {NULL, NULL , 5, UNKNOWN_NODE_STATE};
	Node rightChild = {NULL, NULL , 20, UNKNOWN_NODE_STATE};
	Node root = {&leftChild, &rightChild , 10, UNKNOWN_NODE_STATE};
	Stack stack;
	printf("---------------------------------------------------------------------\n");
	
	//mock
	printf("Starts test_binary_tree_with_3_nodes_parent_left_child_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack , &root);
	display_Expect(5);
	stackPop_ExpectAndReturn(&stack, &root);
	display_Expect(10);
	stackPush_Expect(&stack , &root);
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	//Code
	binaryTreeTraversalInOder(&root);
	
}




/**
 *    10
 *   /  \
 *  -   20
 */
void test_binary_tree_with_2_nodes_parent_and_right_child(void)
{
	Node rightChild = {NULL, NULL , 20, UNKNOWN_NODE_STATE};
	Node root = {NULL, &rightChild , 10, UNKNOWN_NODE_STATE};
	Stack stack;
	printf("---------------------------------------------------------------------\n");
	
	//mock
	printf("Starts test_binary_tree_with_2_nodes_parent_and_right_child\n");
	stackNew_ExpectAndReturn(&stack);
	display_Expect(10);
	stackPush_Expect(&stack , &root);
	display_Expect(20);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	//Code
	binaryTreeTraversalInOder(&root);
	
}




/**
 *    	  10
 *  	 /  \
 *	    5    -
 *     / \
 *    1   7
 */
void test_binary_tree_with_4_nodes_parent_multiple_child(void)
{
	
	Node leftgrandchild = {NULL, NULL, 1, UNKNOWN_NODE_STATE};
	Node rightgrandchild = {NULL, NULL, 7, UNKNOWN_NODE_STATE};
	Node leftChild = {&leftgrandchild, &rightgrandchild , 5 ,UNKNOWN_NODE_STATE};
	Node root = { &leftChild, NULL , 10, UNKNOWN_NODE_STATE};
	Stack stack;
	printf("---------------------------------------------------------------------\n");
	
	//mock
	printf("Starts test_binary_tree_with_4_nodes_parent_and_multiple_child\n");
	stackNew_ExpectAndReturn(&stack);
	stackPush_Expect(&stack , &root);
	stackPush_Expect(&stack , &leftChild);
	display_Expect(1);
	stackPop_ExpectAndReturn(&stack, &leftChild);
	stackPush_Expect(&stack , &leftChild);
	display_Expect(7);
	stackPop_ExpectAndReturn(&stack, &leftChild);
	stackPop_ExpectAndReturn(&stack, &root);
	stackPop_ExpectAndReturn(&stack, NULL);
	stackDel_Expect(&stack);
	
	//Code
	binaryTreeTraversalInOder(&root);
	
}




/**
 *    	  10
 *  	 /  \
 *	    5    -
 *     / \
 *    1   -
 */
void test_printLinear_should_get_1_5_10()
{
	Node leftgrandchild = {NULL, NULL, 1};
	Node leftChild = {&leftgrandchild, NULL , 5};
	Node root = { &leftChild, NULL , 10};
	Stack stack;
	printf("---------------------------------------------------------------------\n");
	printf("Starts test_printLinear_should_get_1_5_10\n");

	printLinear(&root);

}



/**
 *    	  10
 *  	 /  \
 *	    5    12
 *     / \   / \
 *    1   7 11  19
 */
void test_binaryTreePrintInOrder_should_get_1_5_7_10_11()
{
	Node leftgrandchild = {NULL, NULL, 1};
	Node rightgrandchild = {NULL, NULL, 7};
	Node leftgrandchild1 = {NULL, NULL, 11};
	Node rightgrandchild1 = {NULL, NULL, 19};
	Node leftChild = {&leftgrandchild, &rightgrandchild , 5};
	Node rightchild = { &leftgrandchild1, &rightgrandchild1, 12};
	Node root = { &leftChild, &rightchild , 10};
	Stack stack;
	printf("---------------------------------------------------------------------\n");
	printf("Starts test_binaryTreePrintInOrder_should_get_1_5_7_10_11\n");

	
	
	binaryTreePrintInOrder(&root);

}