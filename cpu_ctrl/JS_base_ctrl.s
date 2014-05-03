[bits 32]
GLOBAL _JS_hlt 
GLOBAL _JS_cli
GLOBAL _JS_sti
GLOBAL _JS_stihlt
GLOBAL _JS_load_eflags
GLOBAL _JS_store_eflags
 
_JS_hlt:
	HLT
	RET
_JS_cli:
	CLI
	RET
_JS_sti:
	STI
	RET
_JS_stihlt:
	STI
	HLT
	RET	
_JS_load_eflags:;int JS_load_eflags(void);
	PUSHFD
	POP		EAX
	RET
_JS_store_eflags:;void JS_store_eflags(int);
	MOV		EAX,[ESP+4]
	PUSH	EAX
	POPFD
	RET
