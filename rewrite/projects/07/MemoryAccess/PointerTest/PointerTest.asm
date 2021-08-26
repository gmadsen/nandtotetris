@3030
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 3030

@SP
M=M-1
A=M
D=M
@THIS
M=D
// finished popping pointer 0

@3040
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 3040

@SP
M=M-1
A=M
D=M
@THAT
M=D
// finished popping pointer 1

@32
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 32

@SP
M=M-1
A=M
D=M
@R13
M=D
@2
D=A
@THIS
D=M+D
@R14
M=D
@R13
D=M
@R14
A=M
M=D
// finished popping this 2

@46
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 46

@SP
M=M-1
A=M
D=M
@R13
M=D
@6
D=A
@THAT
D=M+D
@R14
M=D
@R13
D=M
@R14
A=M
M=D
// finished popping that 6

@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: pointer 0

@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: pointer 1

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

@2
D=A
@THIS
D=M+D
@R14
M=D
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: this 2

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

@6
D=A
@THAT
D=M+D
@R14
M=D
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: that 6

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
