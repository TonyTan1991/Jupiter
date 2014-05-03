[bits 32]
GLOBAL _JS_Int21
GLOBAL _JS_Int21Entrance
EXTERN _JS_21Processing

_JS_Int21Entrance:;int JS_Int21Entrance(void);
	CALL	int21next@
int21next@:
	POP		EAX
	MOV		EBX,_JS_Int21-int21next@
	ADD		EAX,EBX
	RET
_JS_Int21:;void JS_Int21(void)
	PUSH	ES
	PUSH	DS
	PUSHAD
	MOV		EAX,ESP
	PUSH	EAX
	CALL	_JS_21Processing
	POP		EAX
	;MOV		ESP,EAX
	POPAD
	POP		DS
	POP		ES
	IRETD	