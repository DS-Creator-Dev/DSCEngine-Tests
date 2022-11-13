#include <DSC>

using namespace DSC;

void test_measure_tiles_4bpp()
{
	nds_assert(Measure()._4bpp().tiles(1) == 32);		
	nds_assert(Measure()._4bpp().tiles(256) == 32*256);
	nds_assert(Measure()._4bpp().tiles(30,20) == 32*600);	
	
	for(int i=1;i<=1024;i++)
		nds_assert(Measure()._4bpp().tiles_count(32*i)==i);	
}

void test_measure_tiles_8bpp()
{
	nds_assert(Measure()._8bpp().tiles(1) == 64);
	nds_assert(Measure()._8bpp().tiles(256) == 64*256);
	nds_assert(Measure()._8bpp().tiles(30, 20) == 64*600);
	
	for(int i=1;i<=1024;i++)
		nds_assert(Measure()._8bpp().tiles_count(64*i)==i);;
}

void test_measure_bitmap_8bpp()
{
	for(int w=16;w<=1024;w+=8)	
		for(int h=16;h<=1024;h+=8)		
			nds_assert(Measure()._8bpp().bitmap(w,h) == w*h);
}

void test_measure_bitmap_16bpp()
{
	for(int w=16;w<=1024;w+=8)	
		for(int h=16;h<=1024;h+=8)		
			nds_assert(Measure()._16bpp().bitmap(w,h) == 2*w*h);
}

void test_measure_map_size()
{
	for(int w=32;w<=128;w++)
		for(int h=32;h<=128;h++)
		{
			nds_assert(Measure()._4bpp().text().map_size(8*w,8*h) == 2*w*h);
			nds_assert(Measure()._8bpp().text().map_size(8*w,8*h) == 2*w*h);				
		}
}

void test_measure_map_size_bitmap()
{
	Measure()._8bpp().bitmap().map_size(8*100,8*100); // fatal
}

void test_measure_value()
{
	nds_assert(MeasureValue(127).value()==127);
}

void test_measure_value_cut_fit()
{
	nds_assert(MeasureValue(10).cut().blocks(3).value()==3);
	nds_assert(MeasureValue(10).fit().blocks(3).value()==4);
	
	nds_assert(MeasureValue(10).blocks(3).cut().value()==3);
	nds_assert(MeasureValue(10).blocks(3).fit().value()==4);
}

void test_measure_value_kilobytes()
{
	nds_assert(MeasureValue(0).kilobytes()==0);
	nds_assert(MeasureValue(0).cut().kilobytes()==0);
	nds_assert(MeasureValue(0).fit().kilobytes()==0);
	
	nds_assert(MeasureValue(512).kilobytes()==0);
	nds_assert(MeasureValue(512).cut().kilobytes()==0);
	nds_assert(MeasureValue(512).fit().kilobytes()==1);
	
	nds_assert(MeasureValue(1024).kilobytes()==1);
	nds_assert(MeasureValue(1024).cut().kilobytes()==1);
	nds_assert(MeasureValue(1024).fit().kilobytes()==1);
	
	nds_assert(MeasureValue(2000).kilobytes()==1);
	nds_assert(MeasureValue(2000).cut().kilobytes()==1);
	nds_assert(MeasureValue(2000).fit().kilobytes()==2);
}

void test_measure_value_kilo_blocks()
{
	nds_assert(MeasureValue(32000).blocks(8).kilobytes()==3);
	nds_assert(MeasureValue(32000).cut().blocks(8).kilobytes()==3);
	nds_assert(MeasureValue(32000).fit().blocks(8).kilobytes()==4);
}

void DSC::testmod_init()
{
	testmod_register(test_measure_tiles_4bpp);
	testmod_register(test_measure_tiles_8bpp);
	testmod_register(test_measure_bitmap_8bpp);
	testmod_register(test_measure_bitmap_16bpp);
	testmod_register(test_measure_map_size);
	testmod_register(test_measure_map_size_bitmap, true);
	testmod_register(test_measure_value);
	testmod_register(test_measure_value_cut_fit);
	testmod_register(test_measure_value_kilobytes);
	testmod_register(test_measure_value_kilo_blocks);
}