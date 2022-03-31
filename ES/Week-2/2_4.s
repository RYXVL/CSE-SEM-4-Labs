; Write a program to subtract two 128 bit numbers available in the code memory and store the result in data memory.
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
	ADD R0, R0, #12
	ADD R1, R1, #12
	MOV R3, #4 ; counter
	MOV R7, #1 ; holds the carry during each iteration
L1	LDR R4, [R0], #-4
	LDR R5, [R1], #-4
	SUBS R4, R4, R5
	SUB R4, R4, #1
	ADD R4, R4, R7
	STR R4, [R2], #4
	MOV R7, #0
	ADC R7, #0
	SUBS R3, R3, #1
	BNE L1
STOP B STOP
VAL1 DCD 0X20000001, 0X20000002, 0X20000003, 0X20000004
VAL2 DCD 0X10000001, 0X10000002, 0X10000003, 0X10000004
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
