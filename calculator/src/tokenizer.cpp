#include "tokenizer.hpp" 

// #define DEBUG 

Tokenizer::Tokenizer(std::string expression)  
{ // tokenizes a given expression (EX: "23+2333" -> ["2333", "+", "23"]) 

    stripExpression(expression); 
    #ifdef DEBUG 
        std::cout << "Stripped string: " << expression << std::endl << std::endl;    
    #endif 

    int pointer = 0; 
    std::string curToken = ""; 

    int decimalCount = 0;  // counts the number of decimals for a given token  
    while (pointer < expression.size()) // loop over the expression using a pointer  
    {
        if (!isOperator(expression[pointer])) { // if we have not found an operator yet, keep adding to the curToken string 
            if (isdigit(expression[pointer])){ 
                curToken += expression[pointer];   
            } else if (expression[pointer] == '.') { 
                curToken += expression[pointer];   
            } else  {
                throw std::runtime_error("Tokenization error: Invalid character");  
            }
        } else {  // when we do find an operator, add the curToken string to the stack 
            /* Working with numbers */ 
            if (curToken.size() > 0) {
                if (isValidFloat(curToken)) {
                    expressionQueue.push(curToken);      
                }
            }
                
            decimalCount = 0;
            curToken = "";  // reset the curToken string to an empty string 

            /* Working with operators */  
            std::string operStr; 
            if (expression[pointer] == '+') { // unary plus operator 
                if (pointer == 0) {
                    pointer++;
                    continue; 
                } else if (pointer - 1 >= 0 && isOperator(expression[pointer - 1]) && ((pointer + 1 >= 0 && !isOperator(expression[pointer +1])))){
                    pointer++; 
                    continue; 
                } else {
                    operStr = "+"; 
                }
            } else if (expression[pointer] == '-') // unary negative operator
            {
                if (pointer == 0) {
                    operStr = "m"; 
                } else if (pointer - 1 >= 0 && pointer + 1 < expression.size() && expression[pointer-1] == '(' && expression[pointer+1] == '('){ // (-(-(-3))
                    operStr = "m"; 
                } else if ( pointer - 1 >= 0 && expression[pointer - 1] == ')' ) {  // ((3+3) - 3 ) 
                    operStr = "-";  
                } else if (pointer - 1 >= 0 && isOperator(expression[pointer - 1]) && ( pointer + 1 >= 0 && !isOperator(expression[pointer +1])  )) { 
                    operStr = "m"; 
                } else {
                    operStr = "-"; // it is just a regular subtraction operation
                }
            } else if (expression[pointer] == '*' && (pointer + 1) < expression.size()) { // checking for "** exponation"  
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
        if (isValidFloat(curToken)) {
            expressionQueue.push(curToken);   
        }
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

void Tokenizer::stripExpression(std::string& expr) 
{
    expr.erase(std::remove_if(expr.begin(), expr.end(), ::isspace),
        expr.end());
}

int Tokenizer::countDecimals(std::string token) 
{
    int decimalCount = 0; 
    for (unsigned int i = 0; i < token.size(); i++)
    {
        if (token[i] == '.') { 
            decimalCount++;
        }
    }

    return decimalCount;
}

bool Tokenizer::isValidFloat(std::string token) 
{
    if (token != "." && countDecimals(token) <= 1)  { 
        return true; 
    } else {
        throw std::runtime_error("Tokenization error: Invalid float");
    }
}
