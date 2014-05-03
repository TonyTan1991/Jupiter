[bits 32]
GLOBAL _JS_io_out8
GLOBAL _JS_io_out16
GLOBAL _JS_io_out32
GLOBAL _JS_io_in8
GLOBAL _JS_io_in16
GLOBAL _JS_io_in32


_JS_io_out8:;void JS_io_out8(int port,int data)
	MOV		EDX,[ESP+4]
	MOV		AL,[ESP+8]
	OUT		DX,AL
	RET
_JS_io_out16:;void JS_io_out16(int port,int data)
	MOV		EDX,[ESP+4]
	MOV		AX,[ESP+8]
	OUT		DX,AX
	RET
_JS_io_out32:;void JS_io_out32(int port,int data)
	MOV		EDX,[ESP+4]
	MOV		EAX,[ESP+8]
	OUT		DX,EAX
	RET
_JS_io_in8:;int JS_io_in8(int port)
	MOV		EDX,[ESP+4]
	MOV		EAX,0
	IN		AL,DX
	RET
_JS_io_in16:;int JS_io_in16(int port)
	MOV		EDX,[ESP+4]
	MOV		EAX,0
	IN		AX,DX
	RET
_JS_io_in32:;int JS_io_in32(int port)
	MOV		EDX,[ESP+4]
	IN		EAX,DX
	RET