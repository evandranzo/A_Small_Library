#pragma once
#include <string>
#include <iostream>
#include "ReaderList.h"
#include "ReaderT.h"
#include "BookList.h"
#include "BookT.h"

enum class OperatorT {CHECKOUT, RETURN, REPORT, STATS, PRINT, NONE};

const int MAX_OPERANDS{2};

struct CommandT {
    std::string command;
    OperatorT op;
    std::string operand[MAX_OPERANDS];
    int operandCount;
};

OperatorT StringToOperatorT(std:: string word);
CommandT ParseNextLine(std::ifstream & inFile);