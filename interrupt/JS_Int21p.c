#include"../header/JS_Int_set.h"
#include"../header/JS_CPU_ctrl.h"
#include"../header/JS_Constant.h"
#include"../header/JS_FIFO_Buffer.h"

#define PORT_KEYDATA	0x0060
#define KEYSTEP  		16
#define KEYREAR			0x0000ffff

void JS_21Processing(int *esp){
	JS_io_out8(PIC0_OCW2,0x61);
	unsigned int keydata=JS_io_in8(PORT_KEYDATA);
	keydata<<=KEYSTEP;
	keydata+=KEYREAR;	
	JS_Enqueue_Buffer(keydata);
	return ;
}

