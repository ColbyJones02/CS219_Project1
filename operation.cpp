//Colby Jones
//2-23-2025
//CS 219
//.cpp file for Operation object

#ifndef OPERATION_CPP
#define OPERATION_CPP

#include "operation.h"

Operation::Operation(){
    oper= "";
    operandNum=0;
    realOpNum=0;
    operationCode=-1;

}

Operation::Operation(string o, uint32_t* op, int on, int ron,int opC){
    oper= o;
    
    for(int i=0; i<2; i++){
        operands[i]= op[i]; 
    }

    operandNum= on;
    realOpNum= ron;
    operationCode= opC;
}

Operation::Operation(const Operation& rhs){
    oper= rhs.oper;

    for(int i=0; i<3; i++){
        operands[i]= rhs.operands[i];
    }

    operandNum= rhs.operandNum;
}

//getters
string Operation::getOperator(){
    return oper;
}

uint32_t* Operation::getOperands(){
    return operands;
}

int Operation::getOperandNum(){
    return operandNum;
}

int Operation::getRealOpNum(){
    return realOpNum;
}

int Operation::getOperationCode(){
    return operationCode;
}

//setters
void Operation::setOperator(string o){
    oper= o;
}

void Operation::setOperands(uint32_t* op){
    for(int i=0; i<2; i++){
        operands[i]= op[i]; 
    } 
}

void Operation::setOperandNum(int on){
    operandNum= on;
}

void Operation::setRealOpNum(int ron){
    realOpNum= ron;
}
void Operation::setOperationCode(int oc){
    operationCode= oc;
}

/*The goal is to compare the amount of operands in this object to the assigned #
for the operation*/
bool Operation::checkOperands(Operation op){
    int setNum= op.getOperandNum();
    int compareNum=op.getRealOpNum();

    cout<<op.getRealOpNum()<<" ";

    if(compareNum!= setNum){
        cout<<"ERROR: Inadequate number of operands."<<endl;
        return false;
    }
    else{
        return true;
    }
}

//goes through each valid operator case, and if it is none of them, it throws an error.
bool Operation:: checkOperator(){
    if(oper=="ADD"||oper=="SUB"||oper=="AND"||oper=="OR"||oper=="XOR"||oper=="NOT"||oper=="LSL"||oper=="LSR"||oper=="EQ"||oper=="LT"||oper=="GT"){
        return false;
    }

    else{
       cout<<"ERROR: Invalid Operator"<<endl; 
       return true;
    }
}

void Operation:: determineOperandNum(){
    string op= this->getOperator();

    if(op=="ADD"||op=="SUB"||op=="AND"||op=="OR"||op=="XOR"||op=="LSL"||op=="LSR"||op=="EQ"||op=="LT"||op=="GT"){
        this->setOperandNum(2);
    }

    //case for NOT operator
    else if(op=="NOT"){
        this->setOperandNum(1);
    }
}

//if else lops through each operation case until the objects' operation is found
void Operation::findOperationCode(){
    string op= this->getOperator();
    if(op=="ADD"){
        this->setOperationCode(0);
    }
    else if(op=="SUB"){
        this->setOperationCode(1);
    }
    else if(op=="AND"){
        this->setOperationCode(2);
    }
    else if(op=="OR"){
        this->setOperationCode(3);
    }
    else if(op=="XOR"){
        this->setOperationCode(4);
    }
    else if(op=="NOT"){
        this->setOperationCode(5);
    }
    else if(op=="LSL"){
        this->setOperationCode(6);
    }
    else if(op=="LSR"){
        this->setOperationCode(7);
    }
    else if(op=="EQ"){
        this->setOperationCode(8);
    }
    else if(op=="LT"){
        this->setOperationCode(9);
    }
    else if(op=="GT"){
        this->setOperationCode(10);
    }
}

//provides output depending on which operation is being done.
void Operation::answer(int c){
    uint64_t numAns;
    uint32_t temp= this->getOperands()[1];
    switch(this->getOperationCode()){
        //ADD
        case 0:
           numAns= this->getOperands()[0]+this->getOperands()[1];
            if(numAns> 0xFFFFFFFF){
                cout<< "ERROR: Number too large. Number will truncate to 32 bits."<<endl;
            }
            else{
                cout<< "0x"<<hex<<numAns<< endl;
            }
            break;

        //SUB
        case 1:
            numAns= this->getOperands()[0]-this->getOperands()[1];
            if(numAns> 0xFFFFFFFF){
                cout<< "ERROR: Number too large. Number will truncate to 32 bits."<<endl;
            }
            else{
                cout<< "0x"<<hex<<numAns<< endl;
            }
            break;

        //AND
        case 2:
            numAns= this->getOperands()[0] & this->getOperands()[1];
            cout<< "0x"<<hex<<numAns<< endl;
            break;
        
        //OR
        case 3:
            numAns= this->getOperands()[0] | this->getOperands()[1];
            cout<< "0x"<<hex<<numAns<< endl;
            break;
        
        //XOR
        case 4:
            numAns= this->getOperands()[0]^this->getOperands()[1];
            cout<< "0x"<<hex<<numAns<< endl;
            break;

        //NOT    
        case 5:
            numAns= ~this->getOperands()[0];
            cout<< "0x"<<hex<<numAns<< endl;
            break;

        //LSL
        case 6:
            if(temp>0x20 && temp!= 0xFFFFFFFF){
                cout<<"ERROR: Bit shift number too large."<<endl;
                break;
            }
            else if(temp==0xFFFFFFFF){
                cout<<"ERROR: Negative bit shift"<<endl;
                break;
            }
            else{
                numAns=this->getOperands()[0]<<this->getOperands()[1];
                cout<< "0x"<<hex<<numAns<< endl;
                break;
            }

        //LSR
        case 7:
            if(this->getOperands()[1]>0x20){
                cout<<"ERROR: Bit shift number too large."<<endl;
                break;
            }
            else if(this->getOperands()[1]==0xFFFFFFFF){
                cout<<"ERROR: Negative bit shift"<<endl;
                break;
            }
            else{
                numAns=this->getOperands()[0]>>this->getOperands()[1];
                cout<< "0x"<<hex<<numAns<< endl;
                break;
            }

        //EQ
        case 8:
            if(this->getOperands()[0]=this->getOperands()[1]){
                cout<< "True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }
            break;

        //LT
        case 9:
            if(this->getOperands()[0]<this->getOperands()[1]){
                cout<< "True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }
            break;

        //GT
        case 10:
        if(this->getOperands()[0]>this->getOperands()[1]){
            cout<< "True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
            break;

        default:
            break;
    }
}

#endif