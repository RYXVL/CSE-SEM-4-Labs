; Write an assembly program to find the factorial of an unsigned number using recursion.
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
	LDR R0, =NUM
	LDR R1, =RESULT
	LDR R2, [R0]
	MOV R3, #1
	BL FACT
	STR R3, [R1]
	B STOP
FACT PUSH {R14}
	MUL R3, R3, R2
	SUB R2, R2, #1
	CMP R2, #0
	BEQ L1
	BL FACT
	POP {R14}
L1	BX LR
STOP B STOP
NUM DCD 5
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
