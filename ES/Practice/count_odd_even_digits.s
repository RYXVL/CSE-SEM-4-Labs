; Program to count number of odd and even digits in a number.
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
	LDR R1, =ODD
	LDR R2, =EVEN
	LDR R3, [R0]
	MOV R5, #2
UP	AND R4, R3, 0XF
	MOV R3, R3, LSR #4
	MOV R10, #0
	BL DIV
	CMP R4, #0
	ADDEQ R6, R6, #1
	ADDNE R7, R7, #1
	CMP R3, #0
	BNE UP
	B ET
DIV	SUB R4, R4, R5
	ADD R10, R10, #1
	CMP R4, R5
	BHS DIV
	BX LR
ET STR R6, [R1], #4
   STR R7, [R1]
STOP B STOP
N DCD 0X2323
	AREA mydata, DATA, READWRITE
ODD DCD 0
EVEN DCD 0
	END
