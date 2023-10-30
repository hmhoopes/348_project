#pragma once

#include <iostream> 
#include <cmath>  
#include "parser.hpp" 


/*
Calculates a given postfix expression 
Result is stored in variable final result where it can be printed using printCalculation()  

Calculator has a number of private functions to help with the calculation

getCalculation() is a one size fits all public function which will use the private functions to calculate given 
a specific operand.  
*/
class Calculator 
{
    public: 
        float finalResult; 
        void printCalculation();  


        float evaluatePostfix(std::queue<std::string> postfixQueue); 
        float getCalculation(std::string operand, float num1, float num2);    



    private: 
        float add(float num1, float num2);  
        float subtract(float num1, float num2); 
        float multiply(float num1, float num2);  
        float divide(float num1, float num2) ; 
        float power(float num1, float num2);  
        int modulo(int num1, int num2); 
        float unaryNeg(float num1);  // multiply the given number by -1 


        bool isOperator(std::string token);  



        std::vector<std::string> operators = {"*", "+", "-", "/", "^", "%", "m", "p"};    
}; 