#include <iostream> 
#include "tokenizer.hpp" 
#include "parser.hpp" 
#include "calculator.hpp" 
#include "displaymanager.hpp" 

// #define DEBUG      

void runCalculator()  
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


int main() 
{
    bool running = true;  

    while (running) 
    {
        
        runCalculator();


        char yesOrNo; 

        std::cout << "Would you like to Continue? (y/n): "; 
        std::cin >> yesOrNo; 

        if (yesOrNo == 'n' || yesOrNo == 'N') {
            running = false; 
        } 

        std::cout << std::endl; 


        std::cin.ignore(1000, '\n');  
    }
    
}