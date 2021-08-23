@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 0

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
// finished popping local 0

(BasicLoop.main$LOOP_START)
// finished label LOOP_START

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
// finished popping local 0

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

@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 1

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

@SP
M=M-1
A=M
D=M
@R13
M=D
@0
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
// finished popping argument 0

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
@BasicLoop.main$LOOP_START
D;JNE
//finished if goto BasicLoop.main$LOOP_START

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

(END)
@END
0;JMP
