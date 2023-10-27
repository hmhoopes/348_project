#include "parser.hpp" 



int Parser::getPrecedence(std::string token) 
{
    std::map<std::string, int> precedence; 
    precedence["+"] = precedence["-"] = 1;
    precedence["*"] = precedence["/"] = precedence["%"] = 2; 
    precedence["^"] = precedence["m"] = precedence["p"] = 3; // m and p are unary operators   
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
    return operand != "^" || operand != "m" || operand != "p"; // m, p, and ^ are right associative    
}

void Parser::pushOperator() 
{
    outputQueue.push(operatorStack.top()); 
    operatorStack.pop(); 
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
                pushOperator(); 
            }

            operatorStack.push(token); 

        } else if (token == "(") {   // if token is left parenthesis we push 

            operatorStack.push(token); 

        } else if ( token == ")" ) { 

            if (operatorStack.empty()) { // if ) is the first token, we know for certain we have a mismatched parenthesis  
                throw std::runtime_error("PARSER ERROR: Mismatched parenthesis");     
            }


            while (!operatorStack.empty() && operatorStack.top() != "(")      
            {  
                pushOperator(); 
            }




            if (!operatorStack.empty() && operatorStack.top() == "(") {      
                operatorStack.pop(); 
            } else {
                throw std::runtime_error("PARSER ERROR: Mismatched parenthesis");    
            }

        } else { // if it is a number  



            outputQueue.push(token); 
        }

        exprQueue.pop();  // pop to get the next token 

        /* call print functions for debugging */   
        printOutputQueue(); 
        printOperatorStack();  
    }

    while (!operatorStack.empty()) 
    { // get the remaining operators from the operator stack and put it in the output queue 
        if (operatorStack.top() == "(" || operatorStack.top() == ")")
            throw std::runtime_error("PARSER ERROR: Mismatched parenthesis"); // we know that there was an unclosed parenthesis if the last tokens are parenthesis 

        outputQueue.push(operatorStack.top()); 
        operatorStack.pop(); 
    }

    /* last print calls for debugging */      
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