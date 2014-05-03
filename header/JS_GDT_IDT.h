#ifndef JS_GDT_IDT_H
#define JS_GDT_IDT_H
//=======================================
//option结构
//
//         ----------------
//         | |D| |A| |D | |
//         |G|/|L|V|P|P |S|
//         | |B| |L| |L | |
//         ----------------
//=======================================	
struct JS_GDT{
	short int seg_lim_low;
	short int seg_ad_low;
	char seg_ad_mid;
	char seg_option_type;
	char seg_option_lim_high;
	char seg_ad_high;
};

	

	
struct JS_IDT{
	short int offset_low;
	short int seg_selector;
	short int gate_option;
	short int offset_high;
};
	
	
void JS_InitGDT(void);
void JS_InitIDT(void);
void JS_SetGDT(struct JS_GDT * ,int base,int limit,char type,char option);
void JS_SetIDT(struct JS_IDT * ,int offset,int selector,int gate_option);


#endif