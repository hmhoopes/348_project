#pragma once 
#include <iostream> 
#include <stack>
#include <vector> 
#include <queue> 
#include <algorithm>
#include <cctype>


/* 
The tokenizer will tokenize a given input string from the user into the expressionQueue 

Given an input from the user, it will translate each part of that input into meaningful ints, 
floating points, operators, represented by a string 

It will smartly strip whitespace 

Decimals will not signal a new token must be made. Instead, the tokenizer will know that it
is a floating point 

For '**', each time a '*' is found, the tokenizer will check the next token to see if it is also
a '*', if it is, the token will be stored as a ^ symbol so that it is easy for the parser to 
recognize exponents 

For unary operators, '+' and '-' characters  will check certain cases to see if they are in fact
unary operators 

EX: "2+    3.0004  *   2" -> ["2","+","3.0004","*","2"]  

The expressionQueue that we obtain from the constructor will be used in the parser 
*/
class Tokenizer 
{
    public: 
        std::queue<std::string> expressionQueue; // the expression queue which will be utilized in the parser   

        Tokenizer(std::string expression);  // the constructor will handle user input and add the tokens to the expressionQueue for later use 

        void printQueue();  // prints the expressioNqueue 
        bool isOperator(char token); // checks to see if the individual char token is an operator 
        std::vector<char> operators = {'*', '+', '-', '/', '^', '(', ')', '%'};    
    private: 
        void stripExpression(std::string& expr);  // removes whitespace from expression 

        bool isPlus(char token); // checks to see if token is a unary plus 
        bool isMinus(char token); // checks to see token is a unary minus 

        bool checkInput(char exprChar); //  returns true if good input
        void handleUnary(); // handle when there is a unary operator   

}; 