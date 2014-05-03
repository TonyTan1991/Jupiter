#include"../header/JS_Window_Graphic.h"
#include"../header/JS_Base_Graphic.h"
void JS_w_Init(){
	JS_w_Desktop();
	JS_w_OperatingFloor();
	JS_w_Mouse(200,200);
	JS_w_Log();
	
	return ;
}
void JS_w_Desktop(){
	JS_Graphic_DrawBox(0,0,-1,-1,10,0,0);
	JS_Graphic_DrawBox(0,0,-1,20,7,0,0);
	return ;


}
void JS_w_Dialog(int x,int y,int width,int hight){



	return ;
}
void JS_w_OperatingFloor(){
	JS_Graphic_DrawBox(-300,0,-1,-1,49,0,0);


	return ;
}

void JS_w_Mouse(int x,int y){
	unsigned char * map=JS_Mouse_Array();
	JS_Graphic_Print(x,y,2,25,map,0);
	return ;
}
void JS_w_Log(void){
	JS_Graphic_DrawBox(10,0,20,20,57,3,1);
	unsigned char * map=JS_ICON1_Array();
	JS_Graphic_Print(12,0,2,20,map,55);

	return ;
}