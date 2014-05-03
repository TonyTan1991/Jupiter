#include"../header/JS_MEM_ctrl.h"
#include"../header/JS_CPU_ctrl.h"


int JS_Memory_size(char unit){
	int step;
	int size;
	int version=JS_CPU_Version();
	switch(unit){
		case 'K': step=0x00000400;break;
		case 'M': step=0x00100000;break;
		default:return -1;
	}
	
	if(version){
		JS_CPU_Disable_cache();
		size=JS_Memory_Test(step);
		JS_CPU_Enable_cache();
	}
	else{
		size=JS_Memory_Test(step);
	}

	size/=step;
	
	return size;

}