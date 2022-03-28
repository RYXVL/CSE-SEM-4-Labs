; Write a program to add ten 32 bit numbers available in code memory and store the result in data memory
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
	LDR R0,=SRC
	LDR R1, =RESULT
	MOV R2,#10
	MOV R3, #0
UP	LDR R4, [R0], #4
	ADD R3, R3, R4
	SUBS R2,#1
	BNE UP
	STR R3, [R1]
STOP B STOP
SRC DCD 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
