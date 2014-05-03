#ifndef		JS_VGA_H
#define 	JS_VGA_H
#define VGAINFO_BASE 		0x2000
#define VGA_X_VALUME		0x2002
#define VGA_Y_VALUME		0x2004
#define VGA_RAM_ADDRESS		0x2008


struct VGAInfo{
	char mode;
	short  x;
	short  y;
	char * addr;
};

#endif