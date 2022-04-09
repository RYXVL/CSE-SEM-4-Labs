; Write an ARM assembly language program to convert a 32 bit BCD number in unpacked form into packed form.
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
	LDR R1, =NUM2
	LDR R2, =RESULT
	LDR R3, [R0]
	LDR R4, [R1]
	MOV R3, R3, LSL #4
	ORR R3, R3, R4
	STR R3, [R2]
STOP B STOP
NUM1 DCD 0X04
NUM2 DCD 0X05
	AREA mydata, DATA, READWRITE
RESULT DCD 0
	END
