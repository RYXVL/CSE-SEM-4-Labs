; Write a program to add two 128 bit numbers available in code memory and store the reuslt in data memory.
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
	MOV R7, #0 ; holds the carry during each iteration
L1	LDR R5, [R0], #-4
	LDR R6, [R1], #-4
	ADD R6, R6, R7 ; added previous carry to one of the numbers
	ADDS R5, R5, R6
	MOV R7, #0
	ADC R7, #0
	STR R5, [R2], #4
	SUBS R3, R3, #1
	BNE L1
STOP B STOP
VAL1 DCD 0X10000001, 0X10000002, 0X10000003, 0X10000004
VAL2 DCD 0X20000001, 0X20000002, 0X20000003, 0X20000004
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END