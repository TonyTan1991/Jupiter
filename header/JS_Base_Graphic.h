#ifndef JS_BASE_GRAPHIC_H
#define JS_BASE_GRAPHIC_H
//---------------------------------------------------------------------------------------//
//函数说明
//x，y为起始坐标
//width，hight为宽和高
//colorType为颜色标号
//type为box的类型
//type=0为普通的标准实心方框（默认）
//type=1为普通的标准空心方框 thickness为边的像素大小（单位像素）
//type=2为圆角实心方框
//type=3为圆角空心方框thickness为边的像素大小（单位像素）
//
//---------------------------------------------------------------------------------------//	
void JS_Graphic_DrawBox(int x,int y,int width,int hight,unsigned char colorType,int type,int thickness);

//---------------------------------------------------------------------------------------//
//函数说明
//x，y为起始坐标
//width为宽度，单位为字节，一个字节表示八个像素的状态，hight为宽和高大小为像素
//colorType为颜色标号
//---------------------------------------------------------------------------------------//	

void JS_Graphic_Print(int x,int y,int width_byte,int hight,unsigned char * map,unsigned char colorType);
#endif