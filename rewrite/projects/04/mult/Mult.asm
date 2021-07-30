// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.
@loopvar
M=0
@R2
M=0

(LOOP)
// if loopvar > R1 goto stop

// CHECK  loop var to R2 to see if terminate
@R1
D=M
@loopvar
D=D-M
@END
D;JEQ

// inc loop var
@loopvar
M=M+1

// get r0 val
@R0
D=M
// add
@R2
M=D+M
@LOOP
0;JMP

// terminating end loop
(END)
@END
0;JMP
