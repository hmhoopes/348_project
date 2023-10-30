#pragma once 
#include <vector> 
#include <queue> 
#include <algorithm> 
#include <map>
#include <ctype.h> 


#include "tokenizer.hpp" 

/* 
Parses a given expression queue that has been tokenized by the tokenizer. 
Uses an algorithm to convert the infix notation (expressed passed by user input) 
to postfix notation (a notation which is easier to calculate with). 

The infixToPostfix algorithm uses a queue and a stack to temporarily place operators 
in the operatorStack and place them back in the outputQueue when needed to facilitate PEMDAS requirements.  
The outputQueue is used for future use for the calculator class 

For precedence, the parser uses a map which corresponds to PEMDAS rules  

The parser takes into account unary operations by receiving m and p tokens from the tokenizer   

EX: ["3", "+", "2", "*", "5"] -> ["3", "2", "5", "*", "+"]   

*/ 
class Parser 
{
    public: 
        std::queue<std::string> outputQueue;  // the final output queue which we will use to calculate the postfix expression
        std::stack<std::string> operatorStack; // the operator stack where we store our operators

        Parser(std::queue<std::string> exprQueue);  
        void infixToPostfix(std::queue<std::string> exprQueue); // algorithm that converts infix to reverse postfix notation and returns the reverse postfix notation 
         
    private: 
        void printOutputQueue(); // prints the output queue 
        void printOperatorStack(); // prints the operator stacke
        void pushOperator();  // pushes the top of the operator stack to the poutputQueue and pops the operatorStack
        bool isLeftAssociative(std::string operand); // checks if the operand is left associative (not ^ or m)
        bool isOperator(std::string token); // checks if a token is an operator 
        int getPrecedence(std::string token);  // gets the precedence of a specific operator 
        std::vector<std::string> operators = {"*", "+", "-", "/", "^", "%", "m", "p"};  // m and p are unary operators          
};  

