#include <DSC>

using namespace DSC;

int hash(const int& x) { return (x>0?x:-x)%256; } 

void test_add()
{
	HashMap<int, int, hash, 256> hm;
	
	for(int i=-10;i<=10;i++) 
		hm[i] = i*i;
	
	for(int i=-100;i<=100;i++) 
	{
		if(i<-10 || i>10)
		{
			nds_assert(!hm.contains_key(i));
		}
		else 
		{
			nds_assert(hm.contains_key(i));
		}			
	}		
}

void test_access()
{
	HashMap<int, int, hash, 256> hm;
	
	for(int i=0;i<=10;i++) 
		hm[i] = i*i;
		
	for(int i=0;i<=10;i++)
	{
		assert(hm[i]==i*i);
	}
	assert(hm[11]==0);	
}

void test_remove_key()
{
	HashMap<int, int, hash, 256> hm;
	
	for(int i=0;i<=10;i++) 
		hm[i] = i*i;
	
	for(int i=0;i<=10;i+=2)
	{
		assert(hm.contains_key(i));
		hm.remove_key(i);
		assert(!hm.contains_key(i));
	}	
	
	for(int i=1;i<=10;i+=2)
	{
		assert(hm.contains_key(i));
		hm.remove_key(i);
		assert(!hm.contains_key(i));
	}	
	
	for(int i=11;i<20;i++)
	{		
		assert(!hm.contains_key(i));
		hm.remove_key(i);
		assert(!hm.contains_key(i));
	}
}

void test_heavy()
{
	Debug::log("Heavy test");
	int N=80000;
	HashMap<int, int, hash, 256> hm;
	
	Debug::log("Adding keys");
	for(int i=0;i<N;i++)
	{
		if(i%5000==0)
		{
			Debug::log("Working... i=%i", i);
		}
		hm[i] = i+1;
		hm[-i] = -i+1;
	}
	
	Debug::log("Accessing keys");
	for(int i=0;i<N;i++)
	{
		if(i%5000==0)
		{
			Debug::log("Working... i=%i", i);
		}
		nds_assert(hm[-i]==-i+1);
		nds_assert(hm[i]==i+1);		
	}
	
	Debug::log("Updating keys");
	for(int i=0;i<N;i+=2)
	{
		if(i%5000==0)
		{
			Debug::log("Working... i=%i", i);
		}		
		hm[i]=2*i;
		nds_assert(hm[i]==2*i);
	}
	
	Debug::log("Removing keys");
	for(int i=0;i<N;i++)
	{
		if(i%5000==0)
		{
			Debug::log("Working... i=%i", i);
		}		
		if(i%2==0) 
		{
			hm.remove_key(i);		
		}		
		else
		{
			hm.remove_key(-i);
		}			
	}
	
	Debug::log("Checking removed keys");
	for(int i=1;i<N;i++)
	{
		if(i%5000==0)
		{
			Debug::log("Working... i=%i", i);
		}		
		if(i%2==0) 
		{
			nds_assert(hm.contains_key(-i));
			nds_assert(!hm.contains_key(i));			
		}		
		else
		{
			nds_assert(!hm.contains_key(-i));
			nds_assert(hm.contains_key(i));
		}			
	}
	
	
	
	
}

void DSC::testmod_init()
{
	testmod_register(test_add);	
	testmod_register(test_access);	
	testmod_register(test_remove_key);
	testmod_register(test_heavy);
}