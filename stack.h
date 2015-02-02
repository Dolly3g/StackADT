#include "linkedList.h"
typedef struct stack Stack;

struct stack{
	LinkedList* list;
};

Stack createStack(void);
int push(Stack,void*);
void* pop(Stack);
