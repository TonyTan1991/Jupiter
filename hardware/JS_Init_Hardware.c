#include"../header/JS_Hardware.h"
#include"../header/JS_CPU_ctrl.h"
#include"../header/JS_Constant.h"

#define PORT_KEYDAT					0x0060
#define PORT_KEYSTA					0x0064
#define PORT_KEYCMD					0x0064
#define KEYSTA_SEND_NOTREADY		0x02
#define KEYCMD_WRITE_MODE			0x60
#define KBC_MODE					0x47 

#define KEYCMD_SENDTO_MOUSE			0xd4
#define MOUSECMD_ENABLE				0xf4



void JS_Init_Hardware(void){
	JS_io_out8(PIC0_IMR, 0xf9); 
	JS_io_out8(PIC1_IMR, 0xef);
	JS_Init_Keyboard();
	JS_Init_Mouse();


}
void JS_Wait_KBC(void){
	while(1)
		if(0==((JS_io_in8(PORT_KEYSTA))&KEYSTA_SEND_NOTREADY))
			break;
	return ;

}
void JS_Init_Keyboard(void){
	JS_Wait_KBC();
	JS_io_out8(PORT_KEYCMD,KEYCMD_WRITE_MODE);
	JS_Wait_KBC();
	JS_io_out8(PORT_KEYDAT,KBC_MODE);
	return ;
}
void JS_Init_Mouse(void){
	JS_Wait_KBC();
	JS_io_out8(PORT_KEYCMD,KEYCMD_SENDTO_MOUSE);
	JS_Wait_KBC();
	JS_io_out8(PORT_KEYDAT,MOUSECMD_ENABLE);
	return ;


}
