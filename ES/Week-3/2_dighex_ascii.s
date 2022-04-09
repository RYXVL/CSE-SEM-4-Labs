; Write an ARM assembly language program to convert 2-digit hexadecimal number into ascii format.
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
	LDR R2, [R0]
	MOV R1, R2, LSR #4
	AND R2, R2, #2_00001111
	ORR R1, R1, #2_00110000
	ORR R2, R2, #2_00110000
	LDR R3, =RESULT
	STR R1, [R3], #4
	STR R2, [R3]
STOP B STOP
NUM DCD 0X24
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
