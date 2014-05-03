#include"../header/JS_Int_set.h"
#include"../header/JS_CPU_ctrl.h"
#include"../header/JS_Constant.h"
#include"../header/JS_FIFO_Buffer.h"
#define PORT_KEYDATA	0x0060
#define MOUSESTEP  		8
#define MOUSEREAR		0x000000ff


void JS_2cProcessing(int *esp){
	JS_io_out8(PIC1_OCW2,0x64);
	JS_io_out8(PIC0_OCW2,0x62);
	unsigned int mousedata=JS_io_in8(PORT_KEYDATA);
	mousedata<<=MOUSESTEP;
	mousedata+=MOUSEREAR;
	JS_Enqueue_Buffer(mousedata);
	return ;

}