#include <iostream> 
#include "tokenizer.hpp" 
#include "parser.hpp" 
#include "calculator.hpp" 

int main() 
{

    // user input 
    std::string input; 
    std::cout << "Input expression: "; 
    std::getline(std::cin, input); 
    std::cout << std::endl; 


    Tokenizer tok(input);  // tokenization 

    Parser parser;  
    parser.infixToPostfix(tok.expressionQueue);   // parsing from infix to postfix  
    

    // postfix evaluation  
    Calculator calc;  
    calc.evaluatePostfix(parser.outputQueue); 
    calc.printCalculation(); 

     

}