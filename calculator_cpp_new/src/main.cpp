#include <iostream> 
#include "tokenizer.hpp" 
#include "parser.hpp" 

int main() 
{
    std::string input; 
    std::cout << "Input expression: "; 
    std::cin >> input; 
    std::cout << std::endl; 


    Tokenizer tok(input);  

    Parser parser;  
    parser.infixToPostfix(tok.expressionQueue); 

    

}