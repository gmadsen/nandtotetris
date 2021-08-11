@10
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 10

@SP
M=M-1
A=M
D=M
@R13
M=D
@0
D=A
@LCL
D=M+D
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@21
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 21

@22
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 22

@SP
M=M-1
A=M
D=M
@R13
M=D
@2
D=A
@ARG
D=M+D
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@SP
M=M-1
A=M
D=M
@R13
M=D
@1
D=A
@ARG
D=M+D
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@36
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 36

@SP
M=M-1
A=M
D=M
@R13
M=D
@6
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
@42
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 42

@45
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 45

@SP
M=M-1
A=M
D=M
@R13
M=D
@5
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
@SP
M=M-1
A=M
D=M
@R13
M=D
@2
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
@510
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 510

@SP
M=M-1
A=M
D=M
@R13
M=D
@6
D=A
@TEMP
D=M+D
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@0
D=A
@LCL
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
// finished pushing: local 0

@5
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
// finished pushing: that 5

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

@1
D=A
@ARG
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
// finished pushing: argument 1

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
// finished pushing: this 6

@6
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
// finished pushing: this 6

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
@TEMP
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
// finished pushing: temp 6

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
