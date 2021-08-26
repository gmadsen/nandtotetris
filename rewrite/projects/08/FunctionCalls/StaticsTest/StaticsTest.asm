// BootStrapping ROM to sys.init
@256
D=A
@SP
M=D
@Class1.main$ret0
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

(Class1.main$ret0)
// finished calling function Sys.init

(Class1.set)
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

@SP
M=M-1
A=M
D=M
@Class1.0
M=D
// finished popping static 0

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
//increment SP
// finished pushing: argument 1

@SP
M=M-1
A=M
D=M
@Class1.1
M=D
// finished popping static 1

@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 0

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
//finished writing function return Class1.set

(Class1.get)
// finished writing function dec 

@Class1.0
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: static 0

@Class1.1
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
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
//increment SP
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
//finished writing function return Class1.get

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

@6
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 6

@8
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 8

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
@7
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class1.set
0;JMP
// jump to function Class1.set

(Sys.init$ret0)
// finished calling function Class1.set

@SP
M=M-1
A=M
D=M
@5
M=D
// finished popping temp 0

@23
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 23

@15
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 15

@Sys.init$ret1
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
@7
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Class2.set
0;JMP
// jump to function Class2.set

(Sys.init$ret1)
// finished calling function Class2.set

@SP
M=M-1
A=M
D=M
@5
M=D
// finished popping temp 0

@Sys.init$ret2
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
@Class1.get
0;JMP
// jump to function Class1.get

(Sys.init$ret2)
// finished calling function Class1.get

@Sys.init$ret3
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
@Class2.get
0;JMP
// jump to function Class2.get

(Sys.init$ret3)
// finished calling function Class2.get

(Sys.init$WHILE)
// finished label WHILE

@Sys.init$WHILE
0;JMP
//finished goto label Sys.init$WHILE

(END)
@END
0;JMP
// BootStrapping ROM to sys.init
@256
D=A
@SP
M=D
@Class2.main$ret0
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

(Class2.main$ret0)
// finished calling function Sys.init

(Class2.set)
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

@SP
M=M-1
A=M
D=M
@Class2.0
M=D
// finished popping static 0

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
//increment SP
// finished pushing: argument 1

@SP
M=M-1
A=M
D=M
@Class2.1
M=D
// finished popping static 1

@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 0

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
//finished writing function return Class2.set

(Class2.get)
// finished writing function dec 

@Class2.0
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: static 0

@Class2.1
D=M
@SP
A=M
M=D
@SP
M=M+1
//increment SP
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
//increment SP
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
//finished writing function return Class2.get

(END)
@END
0;JMP
