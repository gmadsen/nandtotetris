// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
@R1
D=M
@n
M=D  // set n to ram[1]
@i
M=0
@product
M=0
@R2
M=0

(LOOP)
//check if iteration is over
    @i
    D=M
    @n
    D=D-M
    @STOP
    D;JEQ
// add to product
    @R0
    D=M
    @product
    M=M+D
    @i
    M=M+1
    @LOOP
    0;JMP

(STOP)
@product
D=M
@R2
M=D
@END
0;JMP



(END)
@END
0;JMP
