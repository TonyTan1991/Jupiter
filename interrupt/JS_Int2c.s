[bits 32]
GLOBAL _JS_Int2c
GLOBAL _JS_Int2cEntrance
EXTERN _JS_2cProcessing

_JS_Int2cEntrance:;int JS_Int2cEntrance(void);
	CALL	int2cnext@
int2cnext@:
	POP		EAX
	MOV		EBX,_JS_Int2c-int2cnext@
	ADD		EAX,EBX
	RET
	
_JS_Int2c:;void JS_Int2c(void)
	PUSH	ES
	PUSH	DS
	PUSHAD
	MOV		EAX,ESP
	PUSH	EAX
	CALL	_JS_2cProcessing
	POP		EAX
	;MOV		ESP,EAX
	POPAD
	POP		DS
	POP		ES
	IRETD	
	
DB		"INTER2C"