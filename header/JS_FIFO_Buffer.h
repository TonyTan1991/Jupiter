#ifndef JS_FIFO_BUFFER_H
#define JS_FIFO_BUFFER_H
#define BUFFER_BASE 0x2010
struct JS_FIFO32{
	int *data;
	int buffer_head,buffer_rear,buffer_size,free_size;
};



void JS_Init_Buffer(int * data_base,int buffer_size);
int JS_Enqueue_Buffer(int data);
int JS_Dequeue_Buffer(void);
int JS_Buffer_isEmpty(void);
#endif