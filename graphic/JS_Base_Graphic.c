#include"../header/JS_Base_Graphic.h"
#include"../header/JS_MEM_ctrl.h"
#include"../header/JS_VGA.h"
#define CORNER_RADIUS  10
//---------------------------------------------------------------------------------------//
//函数说明
//x，y为起始坐标
//width，hight为宽和高-1(为最大值)
//colorType为颜色标号
//type为box的类型
//type=0为普通的标准实心方框（默认）
//type=1为普通的标准空心方框 thickness为边的像素大小（单位像素）
//type=2为半圆角实心方框
//type=3为圆角空心方框
//---------------------------------------------------------------------------------------//	




void JS_Graphic_DrawBox(int x,int y,int width,int hight,unsigned char colorType,int type,int thickness){
	struct VGAInfo* Global_vgaInfo= VGAINFO_BASE;
	char *vram=Global_vgaInfo->addr;
	int x_lim=Global_vgaInfo->x;
	int y_lim=Global_vgaInfo->y;
	
//参数有效性检测
	
	while(x<0)
		x+=x_lim;
	while(y<0)
		y+=y_lim;
	if(-1==width)
		width=x_lim-x;
	if(-1==hight)
		hight=y_lim-y;
		
	if(0==type){
		for(int i=y;i<y+hight;i++)
			for(int j=x;j<x+width;j++){
				vram[i*x_lim+j]=colorType;
			}
	}
//空心边框
	else if(1==type){
		for(int i=y;i<y+hight;i++)
			for(int j=x;j<x+width;j++){
				if(i<y+thickness||i>y+hight-thickness||j<x+thickness||j>x+width-thickness)
				vram[i*x_lim+j]=colorType;
			}
	
	}
//绘制圆角矩形，形状如下
//_____*
//____*
//__*
//__*
//_*
	else if(2==type){
		for(int i=y;i<y+3;i++){
			if(i==y)
				for(int j=x+3;j<x+width-3;j++){
					vram[i*x_lim+j]=colorType;
			}
			else if(i==y+1)
				for(int j=x+2;j<x+width-2;j++){
					vram[i*x_lim+j]=colorType;
			}
			else if(i==y+2)
				for(int j=x+1;j<x+width-1;j++){
					vram[i*x_lim+j]=colorType;
			}
			
			
		}
		for(int i=y+3;i<y+hight;i++)
			for(int j=x;j<x+width;j++){
				vram[i*x_lim+j]=colorType;
			}
	}
//	
//	
//
	else if(3==type){
		for(int i=y;i<y+3;i++){
			if(i==y)
				for(int j=x+3;j<x+width-3;j++){
					vram[i*x_lim+j]=colorType;
			}
			else if(i==y+1)
				for(int j=x+2;j<x+width-2;j++){
					vram[i*x_lim+j]=colorType;
			}
			else if(i==y+2)
				for(int j=x+1;j<x+width-1;j++){
					vram[i*x_lim+j]=colorType;
			}
			
			
		}
		
//
		for(int i=y+3;i<y+hight-3;i++)
			for(int j=x;j<x+width;j++){
				vram[i*x_lim+j]=colorType;
			}
			
			
//	
		for(int i=y+hight-3;i<y+hight;i++){
			if(i==y+hight-3)
				for(int j=x+1;j<x+width-1;j++){
					vram[i*x_lim+j]=colorType;
				}
			else if(i==y+hight-2)
				for(int j=x+2;j<x+width-2;j++){
					vram[i*x_lim+j]=colorType;
				}
			else if(i==y+hight-1)
				for(int j=x+3;j<x+width-3;j++){
					vram[i*x_lim+j]=colorType;
				}
			
			
		}
	}

	
	return ;

}

void JS_Graphic_Print(int x,int y,int width_byte,int hight,unsigned char * map,unsigned char colorType){
	struct VGAInfo* Global_vgaInfo= VGAINFO_BASE;
	char *vram=Global_vgaInfo->addr;
	int x_lim=Global_vgaInfo->x;
	int y_lim=Global_vgaInfo->y;
	for(int i=y;i<hight+y;i++){
		for(int j=0;j<width_byte;j++){
			unsigned char data;
			data=map[(i-y)*width_byte+j];
			if(data&0x80) vram[i*x_lim+x+j*8]=colorType;
			if(data&0x40) vram[i*x_lim+x+j*8+1]=colorType;
			if(data&0x20) vram[i*x_lim+x+j*8+2]=colorType;
			if(data&0x10) vram[i*x_lim+x+j*8+3]=colorType;
			if(data&0x08) vram[i*x_lim+x+j*8+4]=colorType;
			if(data&0x04) vram[i*x_lim+x+j*8+5]=colorType;
			if(data&0x02) vram[i*x_lim+x+j*8+6]=colorType;
			if(data&0x01) vram[i*x_lim+x+j*8+7]=colorType;
			
		}
	}
	return ;

}
