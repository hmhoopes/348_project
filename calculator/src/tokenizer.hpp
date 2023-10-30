#pragma once 
#include <iostream> 
#include <stack>
#include <vector> 
#include <queue> 
#include <algorithm>
#include <cctype>


/* 
The tokenizer will tokenize a given input string from the user into the expression queue 
It will smartly recognize whitespace and floating point numbers 

EX: "2+    3.0004  *   2" -> ["2","+","3.0004","*","2"]  

*/
class Tokenizer 
{
    public: 
        std::queue<std::string> expressionQueue;     

        Tokenizer(std::string expression);  


        void printQueue();  
        bool isOperator(char token); 
        std::vector<char> operators = {'*', '+', '-', '/', '^', '(', ')', '%'};    


    private: 
        bool checkInput(char exprChar); //  returns true if good input
        void handleUnary(); // handle when there is a unary operator   

}; 