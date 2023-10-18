#include <iostream> 
#include <string> 
#include <cmath>  

class Calculator 
{
    public: 
        float getCalculation(std::string operand, std::string num1, std::string num2);   

    private: 
        float add(std::string num1, std::string num2); 
        float subtract(std::string num1, std::string num2); 
        float multiply(std::string num1, std::string num2);  
        float divide(std::string num1, std::string num2);   
}; 