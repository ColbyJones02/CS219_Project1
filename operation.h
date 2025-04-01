//Colby Jones
//2-23-2025
//Operation object that keeps track of operation type, and number of operands

#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <cstdint>
using namespace std;


class Operation{
    //the ideal number of values in the array for its designated operation
    int operandNum;
    //used to find the actual number of values in the array.
    int realOpNum;
    int operationCode;
    string oper;
    uint32_t operands[3]= {0};

    public:
    Operation();
    Operation(string, uint32_t*, int, int, int);
    Operation(const Operation&);

    //getters
    string getOperator();
    uint32_t* getOperands();
    int getOperandNum();
    int getRealOpNum();
    int getOperationCode();

    //setters
    void setOperator(string);
    void setOperands(uint32_t*);
    void setOperandNum(int);
    void setRealOpNum(int);
    void setOperationCode(int);

    /*checks the count of operands based on the preset maximum (ADD needing exactly 2, for example)
     from the operandNum variable. Returns a bool value to determine if the process can continue.*/
    bool checkOperands(Operation);

    /*checks if the operation is valid. The method is uses if else loops since switch 
    statments operate with integers*/
    bool checkOperator();

    //determines which operation the problem is using, and returns the acceptable abount of operands for the operator
    void determineOperandNum();

    //uses if else loops until the correct operator is found, then sets operationCode with its responding value
    void findOperationCode();

    //probably the most complicated function in this program. returns an answer depending which operator is stored in the object
    //uses a switch statement with operationCode.
    void answer(int);

};
#endif