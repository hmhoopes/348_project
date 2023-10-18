#pragma once 
#include <vector> 
#include <queue> 
#include <algorithm> 
#include <map>
#include <ctype.h> 


#include "tokenizer.hpp" 

class Parser 
{
    public: 
        std::queue<std::string> outputQueue;  // the final output queue which we will use to calculate the postfix expression
        std::stack<std::string> operatorStack; 

        void infixToPostfix(std::queue<std::string> exprStack); // algorithm that converts infix to reverse postfix notation and returns the reverse postfix notation 
        void printOutputQueue(); 
        void printOperatorStack(); 
    private: 
        bool isLeftAssociative(std::string operand); 
        bool isOperator(std::string token); 
        int getPrecedence(std::string token); 
        std::vector<std::string> operators = {"*", "+", "-", "/", "^"};    

        
};  

