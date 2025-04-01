//Colby Jones
//2-23-2025
//CS 219
// Objective: Read assembly commands from a text file, then process te command and send the output to print out on the terminal

#include "operation.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void displayResults(Operation&);

int main(){

    string op;
    uint32_t temp;
    uint32_t opand [3]= {0};
    string line;
    uint32_t opandReset[3]={0};
    Operation oper;

    bool skip;

    ifstream file("pp1_input.txt");

    if(file.is_open()){
        
        while(getline(file, line)){
            int track= 0;
            stringstream ss(line);
            ss >> op;
            oper.setOperator(op);
            
            oper.determineOperandNum();

                
            while(ss>>hex>>temp){
                opand[track]= temp;
                oper.setOperands(opand);
                oper.setRealOpNum(track);
                track ++;
                
            }
            //prints the result of the calulation
            displayResults(oper);
        }
        oper.setOperands(opandReset);

        file.close();
    }
    else{
        cout<< "Unable to open file."<<endl;
    }
    return 0;
}

void displayResults(Operation& o){
    //finds the operationCode for the operation
    o.findOperationCode();
    cout<< o.getOperator()<<" ";

    int dispCount= o.getRealOpNum();
    
    uint32_t numAns;
    bool boolAns, stop;

    //displays all possible numbers involved in each operation
    for(int i=0; o.getOperands()[i]!=0; i++){
        cout<< "0x"<<hex <<o.getOperands()[i]<<" ";
    }

    cout<< "  : ";

    //error checks for invalid operator or inadequate arguments
    stop= o.checkOperator();
    
    if(stop!= true){
        
        
            //displays result. works with error messages and answers. What is returned depends on the  operationCode
            o.answer(o.getOperationCode());
        
    }
    
}