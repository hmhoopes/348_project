#include "parser.hpp" 



int Parser::getPrecedence(std::string token) 
{
    std::map<std::string, int> precedence; 
    precedence["+"] = precedence["-"] = 1;
    precedence["*"] = precedence["/"] = 2;
    precedence["^"] = 3;
    return precedence[token];
}

bool Parser::isOperator(std::string token) 
{
    for (int i = 0; i < operators.size(); i++) 
    {
        if (token == operators[i]) { // check to see if there is a token in the operators vector which matches the token 
            return true; 
        }
    }

    return false; 
}   

bool Parser::isLeftAssociative(std::string operand) 
{
    return operand != "^"; 
}

void Parser::infixToPostfix(std::queue<std::string> exprQueue)  
{
    while (!exprQueue.empty()) // while there are tokens to be read 
    {
        std::string token = exprQueue.front(); 
        if (isOperator(token)) { // if token is an operator 
        
            // While there is an operator at the top of operatorStack (x) and the token is left-associative or its precedence is less or equal to that of (x), or the token is right-associative and its precedence is less than (x)
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                (getPrecedence(operatorStack.top()) > getPrecedence(token) ||
                (getPrecedence(operatorStack.top()) == getPrecedence(token) && isLeftAssociative(token))) &&
                operatorStack.top() != "(")  

            {
                outputQueue.push(operatorStack.top()); 
                operatorStack.pop(); 
            }
            operatorStack.push(token); 
        } else if (token == "(") {   // if token is left parenthesis we push 
            operatorStack.push(token); 
        } else if (token == ")") {
            while (operatorStack.top() != "(")   
            {
                outputQueue.push(operatorStack.top()); 
                operatorStack.pop(); 
            }


            if (operatorStack.top() == "(") { 
                operatorStack.pop(); 
            } else {
                throw std::runtime_error("Mismatched parenthesis"); 
            }

        } else { // if it is a number  
            outputQueue.push(token); 
        }

        exprQueue.pop();  
        printOutputQueue(); 
        printOperatorStack();  
    }

    while (!operatorStack.empty()) 
    { // get the remaining operators from the operator stack and put it in the output queue 
        outputQueue.push(operatorStack.top()); 
        operatorStack.pop(); 
    }

    printOutputQueue();  
    printOperatorStack();   

}

void Parser::printOutputQueue() 
{
    std::cout << "Output queue: "; 
    std::queue<std::string> queueCopy = outputQueue; 
    while (!queueCopy.empty()) 
    {
        std::cout << queueCopy.front() << ", "; 
        queueCopy.pop(); 
    }
    std::cout << std::endl; 
}

void Parser::printOperatorStack() 
{
    std::cout << "Operator Stack: ";  
    std::stack<std::string> stackCopy = operatorStack; 
    while (!stackCopy.empty()) 
    {
        std::cout << stackCopy.top() << ", ";  
        stackCopy.pop();   
    }

    std::cout << std::endl << std::endl;  
}