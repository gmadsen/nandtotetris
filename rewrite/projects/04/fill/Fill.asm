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

// how many screen rows to fill constant
@3
D=A
@loopend
M=D

(LOOP)
@KBD
D=M
@BLACKED
D;JGT
@WHITE
0;JMP


// fill screen
(BLACKED)
@blackcount
M=0
@SCREEN
D=A
@CURRSCREENPOINTER
M=D

// inner fill loop
(BLACKLOOP)
@blackcount
D=M
@SCREEN
D=D+A
@CURRSCREENPOINTER
M=D
A=D
M=-1

@blackcount
M=M+1
D=M
@loopend
D=M-D
@BLACKLOOP
D;JGE
@LOOP
0;JMP

// clear screen
(WHITE)
@whitecount
M=0
@SCREEN
D=A
@CURRSCREENPOINTER
M=D

// inner fill loop
(WHITELOOP)
@whitecount
D=M
@SCREEN
D=D+A
@CURRSCREENPOINTER
M=D
A=D
M=0

@whitecount
M=M+1
D=M
@loopend
D=M-D
@WHITELOOP
D;JGE
@LOOP
0;JMP





