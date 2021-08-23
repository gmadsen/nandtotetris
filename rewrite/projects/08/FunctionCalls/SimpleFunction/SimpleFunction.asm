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

@1
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
// finished pushing: local 1

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
M=!M
@SP
M=M+1
//finished not 

@0
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
// finished pushing: argument 0

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

@LCL
D=M
@R13
M=D
@5
D=A
@R13
A=M-D
D=M
@R14
M=D
@SP
M=M-1
A=M
D=M
@ARG
M=D
A=A+1
D=A
@SP
M=D
@1
D=A
@R13
A=M-D
D=M
@THAT
M=A
@2
D=A
@R13
A=M-D
D=M
@THIS
M=A
@3
D=A
@R13
A=M-D
D=M
@ARG
M=A
@4
D=A
@R13
A=M-D
D=M
@LCL
M=A
@R14
0;JMP
//finished writing function return 

(END)
@END
0;JMP
