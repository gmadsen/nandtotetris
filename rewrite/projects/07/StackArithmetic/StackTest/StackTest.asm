@17
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 17

@17
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 17

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JEQ
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@17
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 17

@16
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 16

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JEQ
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@16
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 16

@17
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 17

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JEQ
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@892
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 892

@891
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 891

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JGT
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@891
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 891

@892
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 892

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JGT
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@891
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 891

@891
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 891

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JGT
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@32767
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 32767

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 32766

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JGT
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 32766

@32767
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 32767

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JGT
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 32766

@32766
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 32766

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@TRUE_VALUE
D;JGT
@0
D=A
@SP
A=M
M=D
(TRUE_VALUE)
@0
D=!A
@SP
A=M
M=D
@SP
M=M+1

@57
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 57

@31
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 31

@53
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 53

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
M=M+D
@SP
M=M+1 // finished adding 

@112
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 112

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
M=M+D
@SP
M=M+1 // finished substraction 

@SP
M=M-1
A=M
M=-M
@SP
M=M+1

@82
D=A
@SP
A=M
M=D
@SP
M=M+1  // finished pushing: constant 82

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
M=M|D
@SP
M=M+1 // finished AND 

@SP
M=M-1
A=M
M=!M
@SP
M=M+1

(END)
@END
0;JMP
