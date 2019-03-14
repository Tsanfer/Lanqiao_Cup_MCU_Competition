#include "common.h"

#define SEG P0
#define BIT P0

code uchar seg_tab[20]={0xc0,0xf9,0xa4,0xb0,0x99,
												0x92,0x82,0xf8,0x80,0x90,
												0x88,0x83,0xc6,0xa1,0x86,0x8e,
												0x7f,0xbf,0x9c,0xff};
code uchar bit_tab[9]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x00};
uchar disp_val[8]={seg_tab_none,seg_tab_none,seg_tab_none,seg_tab_none,
										seg_tab_none,seg_tab_none,seg_tab_none,seg_tab_none,};

void disp_scan(void)
{
	static uchar pointer=0;
	SEG=seg_tab[seg_tab_none];
	hc138_seg();
	SEG=seg_tab[disp_val[pointer]];
	hc138_none();
	BIT=bit_tab[bit_tab_none];
	hc138_bit();
	BIT=bit_tab[pointer];
	hc138_none();
	if(++pointer==8)
	{
		pointer=0;
	}
}

void disp_val_none(void)
{
	uchar i;
	for(i=0;i<8;i++)
	{
		disp_val[i]=seg_tab_none;
	}
}