#include <iostream>
#include <fstream>
#include "Parser.h"

using namespace std;

OperatorT StringToOperatorT(std:: string word){
    OperatorT op{OperatorT::NONE};

    if (word == "CHECKOUT") {
        op = OperatorT::CHECKOUT; 
    } else if (word == "RETURN") {
        op = OperatorT::RETURN; 
    } else if (word == "REPORT") {
        op = OperatorT::REPORT; 
    } else if (word == "STATS") {
        op = OperatorT::STATS; 
    } else if (word == "PRINT") {
        op = OperatorT::PRINT; 
    } else {
        op = OperatorT::NONE;
    }
    return op;
}
CommandT ParseNextLine(std::ifstream & inFile) {
    CommandT cmd;
    size_t pos;
    string bookUser;

    inFile >> cmd.command;
    
    if (not inFile) {
        cmd.op = OperatorT::NONE;
    } else {
        cmd.op = StringToOperatorT(cmd.command);
        switch(cmd.op) {
            case OperatorT::CHECKOUT:
                getline(inFile, bookUser);
                pos = bookUser.find(':');
				cmd.operand[0] = bookUser.substr(1,pos-1);
				cmd.operand[1] = bookUser.substr(pos+1);
                cmd.operandCount = 2;
                break;
            case OperatorT::RETURN:
            case OperatorT::REPORT:
            case OperatorT::STATS:
            case OperatorT::PRINT:
                getline(inFile, bookUser);
				cmd.operand[0] = bookUser.substr(1);
                cmd.operandCount = 1;
                break;
            case OperatorT::NONE:
            default:
                cmd.operandCount = 0;
                break;
        }
    }
    return cmd;
}