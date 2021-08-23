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
@THAT
M=D
// finished popping pointer 1

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
@THAT
D=M+D
@R14
M=D
@R13
D=M
@R14
A=M
M=D
// finished popping that 0

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
@R13
M=D
@1
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
// finished popping that 1

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

@2
D=A
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: constant 2

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

(FibonacciSeries$MAIN_LOOP_START)
// finished label MAIN_LOOP_START

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
@FibonacciSeries$COMPUTE_ELEMENT
D;JNE
//finished if goto COMPUTE_ELEMENT

@FibonacciSeries$END_PROGRAM
0;JMP
//finished goto label END_PROGRAM

(FibonacciSeries$COMPUTE_ELEMENT)
// finished label COMPUTE_ELEMENT

@0
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
// finished pushing: that 0

@1
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
// finished pushing: that 1

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
// finished popping that 2

@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
// finished pushing: pointer 1

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
M=M+D
@SP
M=M+1
// finished adding 

@SP
M=M-1
A=M
D=M
@THAT
M=D
// finished popping pointer 1

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

@FibonacciSeries$MAIN_LOOP_START
0;JMP
//finished goto label MAIN_LOOP_START

(FibonacciSeries$END_PROGRAM)
// finished label END_PROGRAM

(END)
@END
0;JMP
