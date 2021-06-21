// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
// ok

@SCREEN
D=A
@addr
M=D // addr = screen base address


//@8192 // # of ram registers for screen
@8191
D=A
@size
M=D

//check for input, if any paint black, else paint white
(LOOP)
// start with a fresh iter
@i
M=0

@KBD
D=M
@BLACK
D;JNE
@WHITE
0;JMP

(BLACK)
@addr
D=M
@i
D=D+M
A=D
M=-1

@i
D=M
@size
D=D-M
@LOOP
D;JEQ
@i
M=M+1
@BLACK
0;JMP

(WHITE)
@addr
D=M
@i
D=D+M
A=D
M=0

@i
D=M
@size
D=D-M
@LOOP
D;JEQ
@i
M=M+1
@WHITE
0;JMP
