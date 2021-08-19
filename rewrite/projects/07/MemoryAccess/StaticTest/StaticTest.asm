@111
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 111

@333
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 333

@888
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 888

@SP
M=M-1
A=M
D=M
@StaticTest.0
M=D
@SP
M=M-1
A=M
D=M
@StaticTest.1
M=D
@SP
M=M-1
A=M
D=M
@StaticTest.2
M=D
@StaticTest.1
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: static 3

@StaticTest.2
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: static 1

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
M=M-D
@SP
M=M+1
// finished substraction 

@StaticTest.0
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: static 8

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
M=M+D
@SP
M=M+1
// finished adding 

(END)
@END
0;JMP
