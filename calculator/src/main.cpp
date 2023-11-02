#include <iostream> 
#include "tokenizer.hpp" 
#include "parser.hpp" 
#include "calculator.hpp" 
#include "displaymanager.hpp" 

// #define DEBUG   

int main() 
{

    // user input 
    DisplayManager display; 

    Tokenizer tok(display.input);  // tokenization  

    #ifdef DEBUG
        tok.printQueue(); // for debugging  
    #endif

    Parser parser(tok.expressionQueue);  
    
    // postfix evaluation  
    Calculator calc(parser.outputQueue);   

    // displaying the calculated answer 
    display.printCalculatorAnswer(calc.finalResult); 
}