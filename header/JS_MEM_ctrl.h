#ifndef	JS_MEM_CTRL_H
#define JS_MEM_CTRL_H
void write_mem8(int* addr,int data);
void write_mem16(int* addr,int data);
void write_mem32(int* addr,int data);
int  read_mem8(int * addr);
int  read_mem16(int * addr);
int  read_mem32(int * addr);
int JS_Memory_Test(int step);
int JS_Memory_size(char unit);  //unit = 'B','K','M','G'
#endif