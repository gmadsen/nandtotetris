// BootStrapping ROM to sys.init
@256
D=A
@SP
M=D
@Main.main$ret0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@SP
D=M
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.init
0;JMP
// jump to function Sys.init

(Main.main$ret0)
// finished calling function Sys.init

(Main.fibonacci)
// finished writing function dec 

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
//increment SP
// finished pushing: argument 0

@2
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 2

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@Main_TRUE_VALUE_0
D;JLT
//entering false branch
@0
D=A
@SP
A=M
M=D
@Main_EXIT_CONDITIONAL_0
0;JMP
//entering true branch
(Main_TRUE_VALUE_0)
@0
D=!A
@SP
A=M
M=D
(Main_EXIT_CONDITIONAL_0)
@SP
M=M+1
//increment SP
//finished lt 

@SP
M=M-1
A=M
D=M
@Main.fibonacci$IF_TRUE
D;JNE
//finished if goto Main.fibonacci$IF_TRUE

@Main.fibonacci$IF_FALSE
0;JMP
//finished goto label Main.fibonacci$IF_FALSE

(Main.fibonacci$IF_TRUE)
// finished label IF_TRUE

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
//increment SP
// finished pushing: argument 0

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
A=M
M=D
D=A+1
@SP
M=D
@1
D=A
@R13
A=M-D
D=M
@THAT
M=D
@2
D=A
@R13
A=M-D
D=M
@THIS
M=D
@3
D=A
@R13
A=M-D
D=M
@ARG
M=D
@4
D=A
@R13
A=M-D
D=M
@LCL
M=D
@R14
A=M
0;JMP
//finished writing function return Main.fibonacci

(Main.fibonacci$IF_FALSE)
// finished label IF_FALSE

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
//increment SP
// finished pushing: argument 0

@2
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
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
//increment SP
// finished substraction 

@Main.fibonacci$ret0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@SP
D=M
@6
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Main.fibonacci
0;JMP
// jump to function Main.fibonacci

(Main.fibonacci$ret0)
// finished calling function Main.fibonacci

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
//increment SP
// finished pushing: argument 0

@1
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
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
//increment SP
// finished substraction 

@Main.fibonacci$ret1
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@SP
D=M
@6
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Main.fibonacci
0;JMP
// jump to function Main.fibonacci

(Main.fibonacci$ret1)
// finished calling function Main.fibonacci

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
//increment SP
// finished adding 

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
A=M
M=D
D=A+1
@SP
M=D
@1
D=A
@R13
A=M-D
D=M
@THAT
M=D
@2
D=A
@R13
A=M-D
D=M
@THIS
M=D
@3
D=A
@R13
A=M-D
D=M
@ARG
M=D
@4
D=A
@R13
A=M-D
D=M
@LCL
M=D
@R14
A=M
0;JMP
//finished writing function return Main.fibonacci

(END)
@END
0;JMP
// BootStrapping ROM to sys.init
@256
D=A
@SP
M=D
@Sys.main$ret0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@SP
D=M
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.init
0;JMP
// jump to function Sys.init

(Sys.main$ret0)
// finished calling function Sys.init

(Sys.init)
// finished writing function dec 

@4
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 4

@Sys.init$ret0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
@SP
D=M
@6
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Main.fibonacci
0;JMP
// jump to function Main.fibonacci

(Sys.init$ret0)
// finished calling function Main.fibonacci

(Sys.init$WHILE)
// finished label WHILE

@Sys.init$WHILE
0;JMP
//finished goto label Sys.init$WHILE

(END)
@END
0;JMP
