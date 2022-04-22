; Program to sort ten 32 bit numbers using selection sort in an empty ascending stack.
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
	LDR R0, =64
	LDR R1, =25
	LDR R2, =12
	LDR R3, =22
	LDR R4, =11
	MOV R10, R13              ; storing the starting address of stack pointer in R10
	STM R13!, {R0-R4}	      ; push R0 to R4 into stack
	ADD R8, R10, #4           ; make R8 point to second address from the base of the stack
	MOV R11, R13              ; R11 is pointing to next empty space in the stack
OL	LDMDB R13, {R0}           ; pop the top element of the statck into R0 and considering it the initial largest element, note here no write-back
	SUB R12, R13, #4          ; R12 pointing to the top where element is present 
	SUB R9, R13, #4           ; R10 pointing to the top where element is present
IL	LDMDB R12!, {R1}          ; pop the second element from the stack into R1 with write-back
	CMP R1, R0                ; compare first two elements of the stack (R1 is pointing to the second element)
	MOVGT R2, R0              ; interchange the values in the register if R1> R0
	MOVGT R0, R1
	MOVGT R1, R2
	MOVGT R9, R12             ; R9 contains the address where the largest element is there
	CMP R12, R10              ; condition for checking the termination for innerloop , R10 has base address of the starting of stack
	BNE IL
	LDMDB R13!, {R4}          ; put the top element of the stack into R4 with write back , now r13 is pointing to second top element
	STM R9, {R4}              ; put the element into the address for smallest element
	STM R13, {R0}             ; put the lareget elemet (R0) into top of the stack
	CMP R13, R8               ; address of stack pointer should match the address of second element from the base to exit outerloop
	BNE OL
	LDMDB R11!, {R0-R4}       ;pop all the elements into the registers
STOP B STOP
	END
