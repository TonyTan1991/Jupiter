#include"../header/JS_Base_Graphic.h"
#include"../header/JS_Print.h"
#define NS10 10
#define NS16 16
#define BYTEWIDTH	8;
void JS_Print(int x,int y,char ascii){
	unsigned char *map=JS_Char_Array(ascii);
	JS_Graphic_Print(x,y,1,16,map,44);
	return;
}

void JS_Print_int10(int x,int y,int data){
	int NS=1000000000;
	if(data<0){
		data=-data;
		JS_Print(x,y,'-');
		x+=BYTEWIDTH;
	}
	int times=10;
	while(NS>data&&NS>0){
		NS/=NS10;
		times--;
	}
	if(times==0){
		JS_Print(x,y,'0');	
	}
	while(times){
		char res=data/NS;
		JS_Print(x,y,res+0x30);
		x+=BYTEWIDTH;	
		data=data-res*NS;
		NS=1;
		times--;
		for(int i=1;i<times;i++)
			NS*=NS10;
		
		
	}
	return ;

}
void JS_Print_int16(int x,int y,int data){
	int NS=0x10000000;
	if(data<0){
		data=-data;
		JS_Print(x,y,'-');
		x+=BYTEWIDTH;
	}
	JS_Print(x,y,'0');
	x+=BYTEWIDTH;
	JS_Print(x,y,'x');
	x+=BYTEWIDTH;
	int times=8;
	while(NS>data&&NS>0){
		NS/=NS16;
		times--;
	}
	if(times==0){
		JS_Print(x,y,'0');
		x+=BYTEWIDTH;
		JS_Print(x,y,'0');	
	}
	while(times){
		char res=data/NS;
		if(res<9)
			JS_Print(x,y,res+0x30);
		else
			JS_Print(x,y,res+0x37);
		x+=BYTEWIDTH;	
		data=data-res*NS;
		NS=1;
		times--;
		for(int i=1;i<times;i++)
			NS*=NS16;
		
		
	}
	return ;

}
void JS_Print_int2(int x,int y,int data){
	


}
void JS_Print_string(int x,int y,char *string){
	int restore_x=x;
	for(int i=0;string[i]!='\0';i++){
		if(string[i]=='\n'){
			y+=16;
			x=restore_x;
		}
		else{
			JS_Print(x,y,string[i]);
			x+=BYTEWIDTH;
		}
	}

	return ;
}