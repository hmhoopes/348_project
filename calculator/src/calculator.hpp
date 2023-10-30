#pragma once

#include <iostream> 
#include <cmath>  
#include "parser.hpp" 


/*
Calculates a given postfix expression which is obtained from the parser 
Result is stored in variable final result where it can be printed using printCalculation()  


Calculator has a number of private functions to help with the calculation depending on the operator 
obtained from the postfix queue 

getCalculation() is a one size fits all public function which will use the private functions to calculate given 
a specific operand.  
*/
class Calculator 
{
    public: 
        float finalResult; // the final result we get from evaluatePostfix  

        Calculator(std::queue<std::string> postfixQueue);  

        void printCalculation();  // prints final result 


        float evaluatePostfix(std::queue<std::string> postfixQueue); // calculates a postfix expression
        float getCalculation(std::string operand, float num1, float num2); // given a specific operand, calculate the two nums    



    private: 
        float add(float num1, float num2);  // add 
        float subtract(float num1, float num2); // subtract num2 - num1 
        float multiply(float num1, float num2);  // multiply 
        float divide(float num1, float num2) ; // divide num2 / num 1, check for zero division 
        float power(float num1, float num2);  // num^num1 
        int modulo(int num1, int num2); // num2 % num1
        float unaryNeg(float num1);  // multiply the given number by -1 


        bool isOperator(std::string token);  // check if the token is in the operators vector


        // operators vector 
        std::vector<std::string> operators = {"*", "+", "-", "/", "^", "%", "m", "p"};    
}; 