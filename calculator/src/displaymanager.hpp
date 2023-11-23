#pragma once 
#include <iostream>
#include <string> 

/*
The display mangaer class will provide an interface for the user to input data to the 
project and expect an output corresponding to that input. 

It will work with the calculator class to output a final answer for any input given by the user 
*/
class DisplayManager {
    public: 
        std::string input; // user input stored   
        
        DisplayManager();  // gets input from user 

        void printCalculatorAnswer(float anwser); 
}; 