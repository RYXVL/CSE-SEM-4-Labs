; Add two 32 bit packed BCD numbers and store the result in packed BCD form.
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
	LDR R0, =NUM1
	LDR R10, =NUM2
	LDR R1, =RESULT
	LDR R2, [R0]
	LDR R11, [R10]
	ADD R2, R2, R11
	LDR R3, =0XA
	LDR R5, =0X4
	MOV R4, R2
UP	MOV R8, #0
	BL DIV
	CMP R8, #0
	BEQ FIN2
UP1 MOV R9, R9, LSL R5
	ADD R9, R9, R8
	B UP
DIV CMP R4, R3
	BCC UP2
	SUB R4, R4, R3
	ADD R8, R8, #1
	CMP R4, R3
	BHS DIV
UP2	BX LR
FIN	STR R9, [R1]
FIN2 MOV R9, R9, LSL R5
	ADD R9, R9, R4
	STR R9, [R1]
STOP B STOP
NUM1 DCD 0X19
NUM2 DCD 0X1
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END