#include"../header/JS_GDT_IDT.h"
#include"../header/JS_Constant.h"
#include"../header/JS_Int_set.h"

void JS_InitIDT(void){
	struct JS_IDT *JS_idt=IDT_BASE;
	JS_SetIDT(JS_idt+0x21,JS_Int21Entrance(),3*8,0x8e00);
	JS_SetIDT(JS_idt+0x2c,JS_Int2cEntrance(),3*8,0x8e00);
	//for(int i=0;i<256;i++)
	//	JS_SetIDT(JS_idt+i,0x00,0x00,0x00);
	return ;
}

//------------------------------------------------
//struct JS_IDT{
//	short int offset_low;
//	short int seg_selector;
//	short int gate_option;
//	short int offset_high;
//};
//------------------------------------------------

void JS_SetIDT(struct JS_IDT * idt,int offset,int selector,int gate_option){
	idt->offset_low=(offset&0x0000ffff);
	idt->seg_selector=selector;
	idt->gate_option=gate_option;
	idt->offset_high=(offset&0xffff0000)>>16;
	return ;
}