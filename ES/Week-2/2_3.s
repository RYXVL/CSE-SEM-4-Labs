; Write a program to subtract two 32 bit numbers available in the code memory and store the result in data memory.
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
	LDR R0, =VAL1
	LDR R1, =VAL2
	LDR R2, =RESULT
	LDR R3, [R0]
	LDR R4, [R1]
	SUBS R5, R3, R4
	STR R5, [R2]
STOP B STOP
VAL1 DCD 0X00000020
VAL2 DCD 0X00000010
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END