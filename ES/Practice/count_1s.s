; Program to count number of 1's in a number.
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
	LDR R0, =N
	LDR R1, =RESULT
	LDR R2, [R0]
UP	AND R3, R2, 0X1
	MOV R2, R2, LSR #1
	CMP R3, #1
	ADDEQ R5, R5, #1
	CMP R2, #0
	BNE UP
	STR R5, [R1]
STOP B STOP
N DCD 2_10011001
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
