#ifndef Stack_H
#define Stack_H

typedef struct Stack Stack;

struct Stack
{
	void *topOfStack;
	int length;
};


Stack *stackNew();
void stackPush(Stack *stack , void *element);
void *stackPop(Stack *stack);
void stackDel(Stack *stack);

#endif // Stack_H
