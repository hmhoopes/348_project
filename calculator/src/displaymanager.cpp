#include "displaymanager.hpp" 

DisplayManager::DisplayManager() 
{
        // user input 
    std::cout << "Input expression: "; 
    std::getline(std::cin, input); 
    std::cout << std::endl; 
}


void DisplayManager::printCalculatorAnswer(float answer)    
{
    std::cout << "Answer: " << answer << std::endl; 
}