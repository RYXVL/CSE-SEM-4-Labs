; Write an assembly language program to implement division by repetitive subtaction.
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
	LDR R0, =X
	LDR R1, =Y
	LDR R6, =RESULT
	LDR R2, [R0]
	LDR R3, [R1]
	MOV R8, #0
UP	SUB R2, R2, R3
	ADD R8, R8, #1
	CMP R2, R3
	BHS UP
	STR R8, [R6]
STOP B STOP
X DCD 24
Y DCD 12
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
