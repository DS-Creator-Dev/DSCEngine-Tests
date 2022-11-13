#include <DSC>

using namespace DSC;

int value = 0;

int pow10(int N)
{
	int p=1;
	for(;N--;p*=10);
	return p;
}

template<const int N> void event_handler_no_params(void*, void*)
{
	value += pow10(N);
}

void test_add()
{
	value = 0;
	
	Event e;
	e += event_handler_no_params<0>;
	e += event_handler_no_params<1>;
	e += event_handler_no_params<2>;
	
	e.trigger(nullptr, nullptr);

	nds_assert(value==111);
	
}

void test_remove()
{
	value = 0;
	
	Event e;
	e += event_handler_no_params<0>;
	e += event_handler_no_params<1>;
	e += event_handler_no_params<2>;
	
	e.trigger(nullptr, nullptr);
	nds_assert(value==111);
	
	e-= event_handler_no_params<1>;	
	e.trigger(nullptr, nullptr);
	nds_assert(value==212);
	
	e-= event_handler_no_params<5>;	
	e.trigger(nullptr, nullptr);
	nds_assert(value==313);
	
	e-= event_handler_no_params<0>;	
	e.trigger(nullptr, nullptr);
	nds_assert(value==413);
	
	e-= event_handler_no_params<2>;	
	e.trigger(nullptr, nullptr);
	nds_assert(value==413);	
}

void event_handler_with_sender(void* sender, void*)
{
	value = 1 + (*(int*)sender);
}

void test_sender()
{
	value = 0;
	Event e;
	int sender = 5;
	
	e += event_handler_with_sender;
	e.trigger(&sender, nullptr);
	
	nds_assert(value==1+sender);
}

void event_handler_with_sender_and_args(void* sender, void* args)
{
	value = (*(int*)sender) + (*(int*)args);
}

void test_sender_args()
{
	value = 0;
	Event e;
	int sender = 5;
	int args = 3;
	e += event_handler_with_sender_and_args;
	e.trigger(&sender, &args);
	
	nds_assert(value==sender+args);
}

void test_nullptr()
{
	Event e;	
	e += (EventHandler)nullptr;	
}

void DSC::testmod_init()
{
	testmod_register(test_add);		
	testmod_register(test_remove);		
	testmod_register(test_sender);		
	testmod_register(test_sender_args);
	testmod_register(test_nullptr, true);
}