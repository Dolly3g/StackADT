#include <stdlib.h>
#include "stack.h"

Stack createStack(void){
	Stack s;
	s.list = calloc(1,sizeof(LinkedList));
	return s;
}

int push(Stack s,void* data){
	Node* n = create_node(data);
	add_to_list(s.list,n);
	return s.list->count;
}
void* pop(Stack s){
	return deleteElementAt(s.list,s.list->count-1);
}