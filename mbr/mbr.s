CYLS	EQU		2

	ORG  	0X7C00
	
;-----------------------------------------------------
ENTRANCE:
	MOV		AX,0X7C00
	MOV		DS,AX
	XOR		AX,AX
	MOV		SS,AX
	MOV		DS,AX
	MOV		ES,AX
	MOV		SP,0X7C00
;----------------------------------------------------

	MOV		SI,MESSAGE
SHOW_MESSAGE:
	MOV		AL,[SI]
	ADD		SI,1
	CMP		AL,0
	JE		READ_DISK
	MOV		AH,0X0E
	MOV		BX,0x0F
	INT		0X10
	
	JMP		SHOW_MESSAGE
;----------------------------------------------------	
READ_DISK:
	MOV		AX,0x07e0
	MOV		ES,AX
	MOV		CH,0
	MOV		DH,0
	MOV		CL,2
	MOV		AH,0X02
	MOV		AL,1
	MOV		BX,0
	MOV		DL,0
	INT 	0X13
	JNC		READ_SYSTEM_CORE
;----------------------------------------------------
READ_SYSTEM_CORE:
	MOV		AX,0X2000
	MOV		ES,AX
	MOV		CH,0
	MOV		CL,3
	MOV		DH,0
READ_LOOP:
	MOV		AH,0X02
	MOV		AL,1
	MOV		BX,0
	MOV		DL,0
	INT 	0X13

	MOV		AX,ES
	ADD		AX,0X0020
	MOV		ES,AX
	ADD		CL,1
	CMP		CL,18
	JBE		READ_LOOP
	MOV		CL,1
	ADD		DH,1
	CMP		DH,2
	JB		READ_LOOP
	MOV		DH,0
	ADD		CH,1
	CMP		CH,CYLS
	JB		READ_LOOP
	
	
	JMP		INTO_SYSTEM
;----------------------------------------------------
;----------------------------------------------------
INTO_SYSTEM:
	JMP		0x7e00	
;---------------------------------------------------
	
MESSAGE:
	DB		0X0A
	DB		"MBR LOADED      "
	DB		0X0A
	DB		0
;----------------------------------------------------
		
TIMES 	510-($-$$) DB 0X00
	DB		0x55,0xAA
