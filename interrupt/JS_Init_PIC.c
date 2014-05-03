#include"../header/JS_Init_PIC.h"
#include"../header/JS_Constant.h"
#include"../header/JS_CPU_ctrl.h"
void JS_Init_PIC(void){

	JS_io_out8(PIC0_IMR,0xFF); 		//禁止所有中断
	JS_io_out8(PIC1_IMR,0xFF);		//禁止所有中断
	
	JS_io_out8(PIC0_ICW1,0x11);		//边缘触发模式
	JS_io_out8(PIC0_ICW2,0x20);		//IRQ0~7映射到int20~27
	JS_io_out8(PIC0_ICW3,1<<2);		//PIC1由IRQ2连接
	JS_io_out8(PIC0_ICW4,0x01);		//无缓冲区
	
	JS_io_out8(PIC1_ICW1,0x11);		//边缘触发模式
	JS_io_out8(PIC1_ICW2,0x28);		//IRQ8~15映射到int28~2f
	JS_io_out8(PIC1_ICW3,2);		//PIC1由IRQ2连接
	JS_io_out8(PIC1_ICW4,0x01);		//无缓冲区
	
	JS_io_out8(PIC0_IMR,0xFB);		//11111011PIC1以外全部禁止
	JS_io_out8(PIC1_IMR,0xFF);		//11111111禁止所有中断
	

	return ;

}