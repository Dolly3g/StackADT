#include "stack.h"
#include "expr_assert.h"


void test_createStack_creates_a_stack_with_a_top_and_count(){
	Stack s = createStack();
	assertEqual((int)s.top,0);
	assertEqual(s.count,0);
}

void test_push_puts_the_data_on_the_top_of_stack(){
	Stack s = createStack();
	int data1 = 3;
	int data2 = 4;
	assertEqual(push(&s,&data1),1);
	assertEqual(*(int*)s.top->data,data1);
	assertEqual(push(&s,&data2),2);
	assertEqual(*(int*)s.top->data,data2);
	assertEqual(*(int*)s.top->next->data,data1);
}

void test_pop_deletes_the_data_from_the_top_of_stack(){
	Stack s = createStack();
	int data1 = 3;
	int data2 = 4;
	int data3 = 4;
	push(&s,&data1);
	push(&s,&data2);
	push(&s,&data3);
	assertEqual(*(int*)s.top->data,data3);
	assertEqual(*(int*)pop(&s),data3);
	assertEqual(*(int*)s.top->data,data2);
	assertEqual(*(int*)pop(&s),data2);
	assertEqual(*(int*)s.top->data,data1);
	assertEqual(*(int*)pop(&s),data1);
	assertEqual((int)s.top,0);
	assertEqual((int)pop(&s),0);
}