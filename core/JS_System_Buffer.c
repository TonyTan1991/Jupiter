#include"../header/JS_FIFO_Buffer.h"
//====================================================================
//struct JS_FIFO32{
//	int *data;
//	int buffer_head,buffer_rear,buffer_size,free_size;
//};
//====================================================================

void JS_Init_Buffer(int * data_base,int buffer_size){
	struct JS_FIFO32* buffer=BUFFER_BASE;
	buffer->data=data_base;
	buffer->buffer_head=0;
	buffer->buffer_rear=0;
	buffer->buffer_size=buffer_size;
	buffer->free_size=buffer_size;
	return;
}
int JS_Enqueue_Buffer(int data){
	struct JS_FIFO32* buffer=BUFFER_BASE;
	if(0==buffer->free_size)
		return -1;
	(buffer->data)[buffer->buffer_rear]=data;
	(buffer->buffer_rear)++;
	if((buffer->buffer_rear)>=(buffer->buffer_size))
		(buffer->buffer_rear)%=(buffer->buffer_size);
	(buffer->free_size)--;
	return 1;
}
int JS_Dequeue_Buffer(){
	struct JS_FIFO32* buffer=BUFFER_BASE;
	if((buffer->buffer_size)==(buffer->free_size))
		return -1;
	int data=buffer->data[buffer->buffer_head];
	buffer->data[buffer->buffer_head]=0;
	buffer->buffer_head++;
	if((buffer->buffer_head)>=(buffer->buffer_size))
		(buffer->buffer_head)%=(buffer->buffer_size);
	buffer->free_size++;
	return data;
}

int JS_Buffer_isEmpty(){
	struct JS_FIFO32* buffer=BUFFER_BASE;
	return (buffer->free_size==buffer->buffer_size);
}