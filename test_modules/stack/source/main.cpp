#include <DSC>

using namespace DSC;

int hash(const int& x) { return (x>0?x:-x)%256; } 

void test_push_pop()
{
	Stack<int> stack;
	stack.push(4);
	stack.push(3);
	stack.push(2);
	stack.push(1);
	
	nds_assert(stack.pop()==1);
	nds_assert(stack.pop()==2);
	nds_assert(stack.pop()==3);
	nds_assert(stack.pop()==4);		
}

void test_pop_invalid()
{
	Stack<int> stack;	
	stack.push(2);
	stack.push(1);
	
	nds_assert(stack.pop()==1);
	nds_assert(stack.pop()==2);
		
	stack.pop(); // fatal	
}


void test_from_range()
{	
	Stack<int> stack = Stack<int>::from_range(0,10,1);
	
	for(int i=9;i>=0;i--)
		nds_assert(stack.pop()==i);
	nds_assert(stack.is_empty());
}

void test_from_range_invalid()
{
	Stack<int> stack = Stack<int>::from_range(0,10, -1);
}

void test_from_range_invalid_neg()
{
	Stack<int> stack = Stack<int>::from_range(10,0, 1);
}


void DSC::testmod_init()
{
	testmod_register(test_push_pop);	
	testmod_register(test_pop_invalid, true);
	testmod_register(test_from_range);
	testmod_register(test_from_range_invalid, true);
	testmod_register(test_from_range_invalid_neg, true);	
}