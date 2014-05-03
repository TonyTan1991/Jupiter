#include"../header/JS_CPU_ctrl.h"
#include"../header/JS_MEM_ctrl.h"
#include"../header/JS_Constant.h"
#include"../header/JS_VGA.h"
#include"../header/JS_Base_Graphic.h"
#include"../header/JS_Init_PIC.h"
#include"../header/JS_Int_set.h"
#include"../header/JS_GDT_IDT.h"
#include"../header/JS_Print.h"
#include"../header/JS_FIFO_Buffer.h"
#include"../header/JS_Hardware.h"

#define SYSTEM_BUFFER_DATA_BASE	0x19000
#define MOUSE_BUFFER_DATA_BASE	0x2030

void Jupiter(){
	
	//JS_cli();
	int mem_size=JS_Memory_size('M');
	//
	JS_Init_Buffer(SYSTEM_BUFFER_DATA_BASE,512);
	JS_InitGDT();
	JS_InitIDT();
	JS_Init_PIC();
	
	JS_w_Init();
	JS_Print_int10(400,300,mem_size);
	
	JS_Init_Hardware();
	
	//int mem_size=JS_Memory_size('M');
	//JS_Print_int10(400,300,mem_size);
	JS_Print(450,300,'M');
	//JS_sti();
	int *mousedata=MOUSE_BUFFER_DATA_BASE;
	int flag=0;
	while(1){
		JS_cli();
		if(JS_Buffer_isEmpty())
			JS_stihlt();
		else{
			int buffer_data32=JS_Dequeue_Buffer();
			JS_sti();
			if((buffer_data32>0x0000ffff)&&(buffer_data32<=0x00ffffff)){
				unsigned char data=buffer_data32>>16;
				JS_Graphic_DrawBox(300,400,50,20,10,0,0);
				JS_Print_int16(300,400,data);
				
			}
			else if((buffer_data32>=0x000000ff)&&(buffer_data32<=0x0000ffff)){
				unsigned char data=buffer_data32>>8;
				if(data==0xfa&&(flag==0))
					flag=1;
				else if(flag==1){
					mousedata[flag-1]=data;
					flag=2;
				}
				else if(flag==2){
					mousedata[flag-1]=data;
					flag=3;
				}
				else {
					mousedata[flag-1]=data;
					flag=1;
				}
				JS_Graphic_DrawBox(300,450,200,20,10,0,0);
				JS_Print_int16(300,450,mousedata[0]);
				JS_Print_int16(350,450,mousedata[1]);
				JS_Print_int16(400,450,mousedata[2]);
			
			}
			
		}
		
		//JS_hlt();
		
		
	}
	
}





