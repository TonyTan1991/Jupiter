#include"../header/JS_GDT_IDT.h"
#include"../header/JS_Constant.h"

void JS_InitGDT(void){
	struct JS_GDT *JS_gdt=GDT_BASE;
	for(int i=6;i<8192;i++)
	JS_SetGDT(JS_gdt+i,0x00,0x00,0x00,0x00);
	return ;

}
//------------------------------------------
//struct JS_GDT{
//	short int seg_lim_low;
//	short int seg_ad_low;
//	char seg_ad_mid;
//	char seg_option_type;
//	char seg_option_lim_high;
//	char seg_ad_high;
//};
//------------------------------------------
//=======================================
//option结构
//
//         ----------------
//         | |D| |A| |D | |
//         |G|/|L|V|P|P |S|
//         | |B| |L| |L | |
//         ----------------
//=======================================


void JS_SetGDT(struct JS_GDT* gdt,int base,int limit,char type,char option){
	gdt->seg_lim_low=limit&0x0000ffff;
	gdt->seg_ad_low=base&0x0000ffff;
	gdt->seg_ad_mid=(base>>16)&0x00ff;
	gdt->seg_option_type=((option&0x0f)<<4)|(type&0x0f);
	gdt->seg_option_lim_high=(((limit>>16)&0x000f))|(option&0xf0);
	gdt->seg_ad_high=(base&0xff000000)>>24;
	return ;
}