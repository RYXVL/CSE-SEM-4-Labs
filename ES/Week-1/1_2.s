; Write an ARM assembly language program to transfer a 32 bit number from one location in the data memory to another location in the data memory.
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10000000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =OP1;
	LDR R3, [R0]
	LDR R1, =OP2;
	STR R3, [R1]
STOP
	B STOP
	AREA MDATA, DATA, READONLY
OP1 DCD 0X1678
	AREA mydata, DATA, READWRITE
OP2 DCD 0X00
	END