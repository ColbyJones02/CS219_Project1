Project Report//
Colby Jones

To run this program: I used WSL2 in VSCode. Then, type "make" into the terminal. To run the program, type "./PP1" into the terminal.
The code uses a makfile to organize compilation between files

Process:
The program reads each line from a seperate text file until the end has been reached. In each loop. the first variable stored is always the operator.
This is stored as a string, and will get a "identifier" for which one it is. The other variables that are stored are the hex values until the end of the line 
has been reached. all of these are stre as unit32_t variables. All values scanned from the file are stored in an Operation object. 

The next process is to redisplay the input with either an error or the ouput of the operator. The program determines if the input is a valid operator, and if 
the number of operands is correct for the operation. If these are not the case, it will determine the operation(through uint32_t and bool) and displays the 
result.

For each operation, here is the logic:
AND- adds the first and second operand stored in the Operation object. If the number is larger than 0xFFFFFFFF, then an error will be thrown instead of 
a calculation

SUB- subtracts the first and second operand stored in the Operation object. If the number is smaller than 0x0, then an error will be thrown instead of 
a calculation

AND- uses the &(AND) operation between the first and second operation.

OR- uses the |(OR) operation between the first and second operation.

XOR- uses the ^(XOR)operation between the first and second operation.

NOT- uses the ~(NOT)operation between the first and second operation.

LSL- uses the <<(LSL)operation to shift the value of the first operand by the number of times of the second. If the number of shifts is >0x20, then 
an error is thrown for too many shifts. If the number of shifts is negative, then a negative shift error will output instead.

LSR- uses the >>(LSR)operation to shift the value of the first operand by the number of times of the second. If the number of shifts is >0x20, then 
an error is thrown for too many shifts. If the number of shifts is negative, then a negative shift error will output instead.

EQ- uses = between the first and second operand. if they are not equal, the program outputs "false", and "true" if they are.

LT- prints "true" or "false" depending on the operator < comparing operand 1 vs operand 2. if the first is less than the second, the ouput is true. Otherwise,
it is false.

GT-prints "true" or "false" depending on the operator > comparing operand 1 vs operand 2. if the first is greater than the second, the ouput is true. Otherwise,
it is false.


Invalid cases:
One of the biggest bugs in this program is one where the uint32_t values are changed between functions.
This meant I could not fully implement the error message for too many operands, since the variable realOpNum
changed to an inoperable number.

Input Text(Copy from first line):
ADD 0x1234 0x8765     
SUB 0x32 0x14     
AND 0xD 0x9       
OR 0xAFF011          
XOR 0x15 0xF      
NOT 0xFFFFFFFFF    
LSR 0xAAA558 -0x1     
LSL 0x40 0x21    
Invalid 0xC 0x5       
EQ 0xA 0xA      
LT 0xA 0xF     
GT 0xF 0xA     
EQ 0xA        
AND 0xA 0xF 0x1 
ADD 0x1 0xFFFFFFFF 
SUB 0xFFFFFFFF 0x20
5 0x20000 0x9  
ADD 0x72DF9901 0x2E0B484A
LSL 0xFFFFFFFF 0x2
GT 0xA 0xF