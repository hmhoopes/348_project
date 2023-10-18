#pragma once 
#include <iostream> 
#include <stack>
#include <vector> 
#include <queue> 



class Tokenizer 
{
    public: 
        std::queue<std::string> expressionQueue;     

        Tokenizer(std::string expression);  


        void printQueue();  
        bool isOperator(char token); 
        std::vector<char> operators = {'*', '+', '-', '/', '^', '(', ')'};   


    private: 
        bool checkInput(char exprChar); //  returns true if good input 

}; 