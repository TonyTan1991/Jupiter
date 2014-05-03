[bits 32]
GLOBAL _write_mem8
GLOBAL _write_mem16
GLOBAL _write_mem32



_write_mem8:;void _write_mem8(int addr,int data)
	
	MOV		ECX,[ESP+4]
	MOV		AL,[ESP+8]
	MOV		[ECX],AL
	RET
_write_mem16:;void _write_mem16(int addr,int data)
	
	MOV		ECX,[ESP+4]
	MOV		AX,[ESP+8]
	MOV		[ECX],AX
	RET
_write_mem32:;void _write_mem32(int addr,int data)
	
	MOV		ECX,[ESP+4]
	MOV		EAX,[ESP+8]
	MOV		[ECX],EAX
	RET

