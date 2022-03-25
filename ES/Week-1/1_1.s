; Write an ARM assembly language program to store data into general purpose registers.
	AREA	RESET, DATA, READONLY
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
	LDR R2, [R0]
	LDR R3, [R1]
STOP B STOP
	AREA MYDATA, DATA, READONLY
VAL1 DCD 0X12345678
VAL2 DCD 0X87654321
	END
