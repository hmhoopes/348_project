#include "calculator.hpp" 

Calculator::Calculator(std::queue<std::string> postfixQueue) 
{
    finalResult = evaluatePostfix(postfixQueue); 
}

void Calculator::printCalculation() 
{
    std::cout << "Answer: " << finalResult << std::endl;    
}


float Calculator::evaluatePostfix(std::queue<std::string> postfixQueue) 
{
    std::vector<float> outputStack;      


    while (!postfixQueue.empty()) // while there are tokens in the queue 
    {
        std::string token = postfixQueue.front();  
        std::string::size_type sz; 

        postfixQueue.pop(); 

        if (!isOperator(token)) 
        {
            float fnum; 
            fnum = std::stof(token, &sz); // convertng to float     
            outputStack.push_back(fnum); 
        } else {
            if (!outputStack.empty()) 
            {
                float first = outputStack.back(); 
                outputStack.pop_back();  
                
                // handling unary operations  
                if (token == "m") {
                    first *= -1; 
                    outputStack.push_back(first); 
                } else {
                    if (outputStack.empty()) {
                        throw std::runtime_error("CALCULATOR ERROR: Operator without operands"); 
                    }

                    float second = outputStack.back(); 

                    outputStack.pop_back(); 

                    float res = getCalculation(token, first, second); 
                    outputStack.push_back(res);     
                }
            }
        }
    }

    if (outputStack.size() > 1) 
        throw std::runtime_error("CALCULATOR ERROR: Missing Operator");  
        
    return outputStack[0]; 
}

float Calculator::getCalculation(std::string operand, float num1, float num2) 
{
    float result; 

    if (operand == "+") {
        result = add(num1, num2); 
    } else if (operand == "-") {
        result = subtract(num1, num2); 
    } else if (operand == "*") {
        result = multiply(num1, num2); 
    } else if (operand == "/") {
        result = divide(num1, num2);  
    } else if (operand == "^") {
        result = power(num1, num2); 
    } else if (operand == "%") {
        result = modulo(num1, num2); 
    }

    return result; 
}

float Calculator::add(float num1, float num2) 
{
    return num1 + num2; 
}

float Calculator::subtract(float num1, float num2)
{
    return num2 - num1;  
}

float Calculator::multiply(float num1, float num2)
{
    return num1 * num2; 
}

float Calculator::divide(float num1, float num2) 
{
    if (num1 == 0) { 
        throw std::runtime_error("CALCULATOR ERROR: Divison by Zero");   
    }

    return num2 / num1; 
}

float Calculator::power(float num1, float num2)  
{
    if ((num2 == 0) && (num1 < 0)){
        throw std::runtime_error("CALCULATOR ERROR: Divison by Zero");   
    }
    return pow(num2, num1);   
}

float Calculator::modulo(float num1, float num2)  
{
    return std::fmod(num2, num1); 
}

float Calculator::unaryNeg(float num1) {
    return num1 * -1.0f;  
}


bool Calculator::isOperator(std::string token) 
{
    for (int i = 0; i < operators.size(); i++) 
    {
        if (token == operators[i]) { // check to see if there is a token in the operators vector which matches the token 
            return true; 
        }
    }

    return false; 
}  