[bits 32]
GLOBAL _read_mem8
GLOBAL _read_mem16
GLOBAL _read_mem32

_read_mem8:;int read_mem8(int *addr)	
	MOV		ECX,[ESP+4]
	XOR		EAX,EAX
	MOV		AL,[ECX]
	RET
_read_mem16:;int read_mem16(int *addr)
	MOV		ECX,[ESP+4]
	XOR		EAX,EAX
	MOV		AX,[ECX]
	RET
_read_mem32:;int read_mem32(int *addr)
	MOV		ECX,[ESP+4]
	XOR		EAX,EAX
	MOV		EAX,[ECX]
	RET