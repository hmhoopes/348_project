#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "node.h"
template <typename T>
class Stack{
    public:
        Node<T>* top;
        Stack<T>(){
            top = nullptr;
        }

        void push(T entry){
            Node<T>* heapNode = new Node<T>(entry);
            heapNode->nextNode = top;
            top = heapNode;
        }   

        bool is_empty(){
            return !top;
        }

        T peek(){
            return top->item;
        }
        
        T pop(){
            T topVal = top->item;
            top = top->nextNode;
            return topVal;
        }

        ~Stack<T>(){
            while (!this->is_empty()){
                Node<T>* curNode = top;
                top = top->nextNode;
                delete curNode;
            }
        }
};
#endif