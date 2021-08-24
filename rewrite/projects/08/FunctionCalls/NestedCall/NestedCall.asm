(Sys.init)
// finished writing function dec 

@4000
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 4000

@SP
M=M-1
A=M
D=M
@THIS
M=D
// finished popping pointer 0

@5000
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 5000

@SP
M=M-1
A=M
D=M
@THAT
M=D
// finished popping pointer 1

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
@5
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.main
0;JMP
// jump to function Sys.main

(Sys.init$ret0)
// finished calling function Sys.main

@SP
M=M-1
A=M
D=M
@R13
M=D
@1
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
// finished popping temp 1

(Sys.init$LOOP)
// finished label LOOP

@Sys.init$LOOP
0;JMP
//finished goto label Sys.init$LOOP

(Sys.main)
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 0

@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 0

@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 0

@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 0

@0
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 0

// finished writing function dec 

@4001
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 4001

@SP
M=M-1
A=M
D=M
@THIS
M=D
// finished popping pointer 0

@5001
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 5001

@SP
M=M-1
A=M
D=M
@THAT
M=D
// finished popping pointer 1

@200
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 200

@SP
M=M-1
A=M
D=M
@R13
M=D
@1
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
// finished popping local 1

@40
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 40

@SP
M=M-1
A=M
D=M
@R13
M=D
@2
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
// finished popping local 2

@6
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 6

@SP
M=M-1
A=M
D=M
@R13
M=D
@3
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
// finished popping local 3

@123
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 123

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
@6
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.add12
0;JMP
// jump to function Sys.add12

(Sys.main$ret0)
// finished calling function Sys.add12

@SP
M=M-1
A=M
D=M
@R13
M=D
@0
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
// finished popping temp 0

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
//increment SP
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
//increment SP
// finished pushing: local 1

@2
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
//increment SP
// finished pushing: local 2

@3
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
//increment SP
// finished pushing: local 3

@4
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
//increment SP
// finished pushing: local 4

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
//finished writing function return Sys.main

(Sys.add12)
// finished writing function dec 

@4002
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 4002

@SP
M=M-1
A=M
D=M
@THIS
M=D
// finished popping pointer 0

@5002
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 5002

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
//increment SP
// finished pushing: argument 0

@12
D=A
@SP
A=M
M=D
@SP
M=M+1
//increment SP
// finished pushing: constant 12

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
//finished writing function return Sys.add12

(END)
@END
0;JMP
