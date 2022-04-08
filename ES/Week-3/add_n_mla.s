; Find the sum of 'n' natural numbers using MLA instruction.
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
	LDR R3, =RESULT
	LDR R1, [R0]
	MOV R2, #1
UP	MLA R5, R2, R5, R1
	SUBS R1, R1, #1
	BNE UP
	STR R5, [R3]
STOP B STOP
N DCD 10
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
