; Write an ARM assembly language program to transfer block of ten 32 bit numbers from code memory to data memorywhen the source and destination blocks are non-overlapping.	
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =SRC
	LDR R1, =DST
	MOV R2, #10
L1 	LDR R3, [R0], #4
	STR R3, [R1], #4
	SUB R2, #1
	CMP R2, #0
	BNE L1
STOP
	B STOP
SRC DCD 11, 12 , 13, 14, 15, 16, 17, 18, 19, 20
	AREA mydata, DATA, READWRITE
DST DCD 0
	END