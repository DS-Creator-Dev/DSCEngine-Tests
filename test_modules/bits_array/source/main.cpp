#include <DSC>

using namespace DSC;

void test_bits()
{
	BitsArray<100> bits;
	
	Debug::log("Direct way");
	for(int i=0;i<100;i++)
	{
		nds_assert(bits[i]==false);
		bits[i] = true;
		nds_assert(bits[i]==true);
	}
	
	Debug::log("Reverse way");
	for(int i=99;i>=0;i--)
	{		
		nds_assert(bits[i]==true);
		bits[i] = false;
		nds_assert(bits[i]==false);
	}	
}

#include <stdlib.h>

void test_find_free_bit()
{
	BitsArray<100> bits;
	
	for(int i=0;i<30;i++)
	{
		int w = rand()%100;
		bits[w] = true; // occupy some positions		
	}
		
	
	for(int pos; (pos = bits.find_free_bit())>=0;)
	{
		// look for the free bit's position the "hard" way
		int brute_force_pos = 0;			
		for(;brute_force_pos<100 && bits[brute_force_pos];brute_force_pos++);		
		
		if(brute_force_pos==100)
			brute_force_pos = -1;						
		
		// check if bits.find_free_bit() has found the same position
		nds_assert(pos == brute_force_pos);
		
		bits[pos] = true; // occupy the free pos		
	}		
	
	// don't Debug.log(...) bits[i] !!!!
	// instead, use bits.at(i) 
}

void test_invalid_index()
{
	BitsArray<100> bits;
	bits[101];
}

void test_invalid_index_2()
{
	BitsArray<100> bits;
	bits[-1];
}

void DSC::testmod_init()
{
	testmod_register(test_bits);		
	testmod_register(test_find_free_bit);		
	testmod_register(test_invalid_index, true);		
	testmod_register(test_invalid_index_2, true);		
}