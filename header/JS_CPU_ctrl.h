#ifndef	JS_CPU_CTRL_H
#define JS_CPU_CTRL_H
void JS_hlt();
void JS_cli();
void JS_sti();
void JS_stihlt();
void JS_io_out8(int port,int data);
void JS_io_out16(int port,int data);
void JS_io_out32(int port,int data);
int JS_io_in8(int port);
int JS_io_in16(int port);
int JS_io_in32(int port);
int JS_load_eflags(void);
void JS_store_eflags(int);
int JS_CPU_Version(void);

void JS_CPU_Enable_cache(void);
void JS_CPU_Disable_cache(void);

#endif