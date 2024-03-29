; Reverse an array of ten 32 bit numbers in the memory.
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
	LDR R0, =DST
	LDR R1, =DST
	ADD R1, #36
	MOV R3, #10
	MOV R2, #5
L1 	STR R2, [R0], #4
	ADD R2, #5
	SUB R3, #1
	CMP R3, #0
	BNE L1
	LDR R0, =DST
L2	LDR R5, [R0]
	LDR R6, [R1]
	STR R6, [R0]
	STR R5, [R1]
	ADD R0, #4
	SUB R1, #4
	CMP R1, R0
	BHS L2
STOP
	B STOP
	AREA mydata, DATA, READWRITE
DST DCD 0
	END