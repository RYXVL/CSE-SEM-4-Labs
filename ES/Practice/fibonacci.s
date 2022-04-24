; Program to print the fibonacci series.
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
	LDR R0, =TERMS
	LDR R1, [R0]
	LDR R2, =RESULT
	MOV R3, #0
	MOV R4, #1
	MOV R5, #1
	STR R3, [R2], #4
	STR R4, [R2], #4
	STR R5, [R2], #4
LP	MOV R3, R4
	MOV R4, R5
	ADD R5, R3, R4
	STR R5, [R2], #4
	SUBS R1, R1, #1
	BNE LP
STOP B STOP
TERMS DCD 5
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
