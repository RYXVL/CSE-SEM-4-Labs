; Write an assembly language program to search an element in an array of ten 32 bit numbers using linear search.
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
	LDR R0, =ARY
	LDR R1, =RESULT
	ADD R4, R0, #20 ;POINTS TO ONE LOCATION AFTER THE LAST ELEMENT IN THE ARRAY
	MOV R2, #13 ;KEY
LP	LDR R3, [R0], #4
	CMP R3, R2
	MOVEQ R5, #1 ;KEY FOUND STORE TRUE VALUE
	BEQ OUT
	CMP R0, R4
	BNE LP
	B STOP
OUT	STR R5, [R1]
STOP B STOP
ARY DCD 64, 25, 12, 22, 11
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
