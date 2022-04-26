; Program to find the smallest and the largest element in an array.
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
	LDR R1, =SMALLEST
	LDR R2, =LARGEST
	ADD R7, R0, #28		;R7 POINTS TO ONE LOCATION AFTER THE LAST ELEMENT OF THE ARRAY
	LDR R3, [R0]		;R3 HAS THE SMALLEST NUMBER
	LDR R4, [R0], #4	;R4 HAS THE LARGEST NUMBER
UP	LDR R5, [R0], #4
	CMP R3, R5
	MOVCS R3, R5
	CMP R4, R5
	MOVCC R4, R5
	CMP R0, R7
	BNE UP
	STR R3, [R1]
	STR R4, [R2]
STOP B STOP
ARY DCD 1, 23, 12, 9, 30, 2, 50
	AREA mydata, DATA, READWRITE
SMALLEST DCD 0
LARGEST DCD 0
	END