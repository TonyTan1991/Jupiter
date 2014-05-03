#ifndef JS_INIT_PIC_H
#define JS_INIT_PIC_H


void JS_Int21(void);
int  JS_Int21Entrance(void);
void JS_21Processing(int *esp);
void JS_Int2c(void);
int  JS_Int2cEntrance(void);
void JS_2cProcessing(int *esp);


#endif