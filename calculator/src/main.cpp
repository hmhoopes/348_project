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
    tok.printQueue(); 

    Parser parser(tok.expressionQueue);  
    
    // postfix evaluation  
    Calculator calc(parser.outputQueue);   
    calc.printCalculation(); // printing final calculation  
}