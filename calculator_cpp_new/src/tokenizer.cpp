#include "tokenizer.hpp" 

Tokenizer::Tokenizer(std::string expression)  
{ // tokenizes a given expression (EX: "23+2333" -> ["2333", "+", "23"]) 

    expression.erase(std::remove_if(expression.begin(), expression.end(), ::isspace),
        expression.end());

    std::cout << "Stripped string: " << expression << std::endl << std::endl;   

    int pointer = 0; 
    std::string curToken = ""; 
    while (pointer < expression.size()) // loop over the expression using a pointer  
    {
        if (!isOperator(expression[pointer])) { // if we have not found an operator yet, keep adding to the curToken string 
            curToken += expression[pointer]; 
        } else {  // when we do find an operator, add the curToken string to the stack 
            /* Working with numbers */ 
            if (curToken.size() > 0)
            {
                expressionQueue.push(curToken); 

            }
            curToken = "";  // reset the curToken string to an empty string 


            /* Working with operators */  
            std::string operStr; 
            if (expression[pointer] == '*' && (pointer + 1) < expression.size()) { // checking for "** exponation"  
                if (expression[pointer + 1] == '*') { 
                    operStr = "^";  
                    pointer++; 
                } else { 
                    operStr = "*"; 
                }
            } else { 
                operStr = std::string(1, expression[pointer]); 
            }
            expressionQueue.push(operStr); // push the operator onto the expression stack  


        }
        pointer++; // increment pointer  

    }

    if (curToken.size() > 0) { // add the last curToken to the expressionStack (usually is the last token in the expression) 
        expressionQueue.push(curToken);  
    }

}

void Tokenizer::printQueue() 
{ // copies the stack and prints it out in a comma seperated list 
    std::queue<std::string> copyQueue = expressionQueue; 

    std::cout << "Initial Input: "; 
    while (!copyQueue.empty()) {
        std::string s = copyQueue.front();  
        std::cout << s << ", "; 
        copyQueue.pop();  
    }

    std::cout << std::endl; 
}

bool Tokenizer::isOperator(char token) 
{
    for (int i = 0; i < operators.size(); i++) 
    {
        if (token == operators[i]) { // check to see if there is a token in the operators vector which matches the token 
            return true; 
        }
    }

    return false; 
}