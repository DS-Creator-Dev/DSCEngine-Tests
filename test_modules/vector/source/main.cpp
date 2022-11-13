/**
	Vector tests
**/

#include <DSC>

using namespace DSC;

void test_create_default()
{
	Vector<int> v;
	nds_assert(v.size()==0);
}

void test_create_capacity()
{
	Vector<int> v(10);
	nds_assert(v.size()==0);
}

template<typename T>
void __add_1_N(Vector<T> &v, int N, bool check = false)
{
	for(int i=1;i<=N;i++)
	{
		v.push_back(i);
		if(check)
		{
			nds_assert(v.size()==i);
			nds_assert(v.back()==i);
		}
	}
}

void test_push_back()
{
	Vector<int> v;
	__add_1_N(v, 100000, true);
	
}

void test_clear()
{
	Vector<int> v;
	__add_1_N(v, 100000);
	v.clear();
	nds_assert(v.size()==0);		
}

void test_index()
{
	const int N = 100000;
	Vector<int> v;
	__add_1_N(v, N);
	for(int i=0;i<N;i++)
	{
		nds_assert(v[i]==i+1);
	}
}

void test_index_out_of_bounds_brackets()
{
	const int N = 10;
	Vector<int> v;
	__add_1_N(v, N);
	
	int x __attribute__((unused)) = v[10]; // error;	
}

void test_index_out_of_bounds_get_at()
{
	const int N = 10;
	Vector<int> v;
	__add_1_N(v, N);
	
	int x __attribute__((unused)) = v.get_at(10); // error;	
}

void test_index_out_of_bounds_lvalue()
{
	const int N = 10;
	Vector<int> v;
	__add_1_N(v, N);
	
	v[10]=5; // error;	
}


void test_move()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	Vector<int> w = _move_(v);
	
	nds_assert(w.size()==3);
	nds_assert(w[0]==1);
	nds_assert(w[1]==2);
	nds_assert(w[2]==3);
	
	nds_assert(v.size()==0); // v was destroyed
}

void test_copy()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	Vector<int> w(v);
	
	nds_assert(w.size()==3);
	nds_assert(w[0]==1);
	nds_assert(w[1]==2);
	nds_assert(w[2]==3);
	
	nds_assert(v.size()==3);
	nds_assert(v[0]==1);
	nds_assert(v[1]==2);
	nds_assert(v[2]==3);
}

void test_remove()
{
	const int N = 10000;
	Vector<int> v;	
	__add_1_N(v, N);
	
	for(int i=0;i<N/2;i++)
	{
		if(i%500==0)
		{
			Debug::log("Working... i=%i",i);
		}
		v.remove(2*i);
	}
	
	for(int i=0;i<N/2;i++)
	{
		nds_assert(v[i]==2*i+1);
	}
}

void test_remove_at()
{
	const int N = 10000;
	Vector<int> v;	
	__add_1_N(v, N);
	
	for(int i=0;i<N/2;i++)
	{
		if(i%500==0)
		{
			Debug::log("Working... i=%i",i);
		}
		v.remove_at(i);
	}
	
	for(int i=0;i<N/2;i++)
	{
		nds_assert(v[i]==2*i+2);
	}	
}

void test_remove_at_out_of_range_0()
{
	const int N = 10000;
	Vector<int> v;	
	__add_1_N(v, N);
	
	v.remove_at(-1);
	
}

void test_remove_at_out_of_range_N()
{
	const int N = 10000;
	Vector<int> v;	
	__add_1_N(v, N);
	v.remove_at(N);
}

void test_reset()
{
	const int N = 10000;
	Vector<int> v;	
	__add_1_N(v, N);
	
	v.reset();
	
	nds_assert(v.size()==0);	
}

void test_resize_enlarge()
{
	const int N = 10000;
	const int K = 5123;
	Vector<int> v;	
	__add_1_N(v, N);
	
	v.resize(N+K);
	
	nds_assert(v.size()==N+K);
	
	for(int i=0;i<N;i++)
	{
		nds_assert(v[i]==i+1);
	}
	
	// Would it be better to also "zero" the resized memory?
	/*for(int i=N;i<N+K;i++)
	{
		nds_assert(v[i]==0);
	}*/						
}

void test_resize_shrink()
{
	const int N = 10000;
	const int K = 5123;
	Vector<int> v;	
	__add_1_N(v, N);
	
	v.resize(K);
	
	nds_assert(v.size()==K);
	
	for(int i=0;i<K;i++)
	{
		nds_assert(v[i]==i+1);
	}	
}

void test_resize_invalid()
{
	const int N = 10000;	
	Vector<int> v;	
	__add_1_N(v, N);
	
	v.resize(-100);
}

void test_find()
{
	const int N = 1000;	
	Vector<int> v;	
	__add_1_N(v, N);
	
	for(int i=1;i<=N;i++)
		nds_assert(v.find(i)==i-1);
	
	for(int i=0;i>-10;i--)
		nds_assert(v.find(i)==-1);
	
	for(int i=N+1;i<N+10;i++)
		nds_assert(v.find(i)==-1);	
}

void DSC::testmod_init()
{
	testmod_register(test_create_default);
	testmod_register(test_create_capacity);
	testmod_register(test_push_back);
	testmod_register(test_clear);
	
	testmod_register(test_index);
	testmod_register(test_index_out_of_bounds_brackets, true);
	testmod_register(test_index_out_of_bounds_get_at, true);
	testmod_register(test_index_out_of_bounds_lvalue, true);
	
	testmod_register(test_move);
	testmod_register(test_copy);
	
	testmod_register(test_remove);
	testmod_register(test_remove_at);
	
	testmod_register(test_remove_at_out_of_range_0, true);
	testmod_register(test_remove_at_out_of_range_N, true);
	
	testmod_register(test_reset);
	
	
	testmod_register(test_resize_enlarge);
	testmod_register(test_resize_shrink);
	testmod_register(test_resize_invalid, true);
	
	testmod_register(test_find);	
}