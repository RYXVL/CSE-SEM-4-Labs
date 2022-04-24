; Program to find x raised to y using recursion.
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
	LDR R2, [R0]
	LDR R3, [R1]
	LDR R4, =RESULT
	MOV R5, #1
	BL POW
	STR	R5, [R4]
	B STOP
POW	PUSH{R14}
	MUL R5, R5, R2
	SUBS R3, R3, #1
	BEQ ET
	BL POW
	POP{R14}
ET	BX LR
STOP B STOP
X DCD 4
Y DCD 4
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
