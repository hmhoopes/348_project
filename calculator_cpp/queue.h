#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
template <typename T>
class Queue{
    public:
        Node<T>* front;
        Node<T>* back;

        Queue<T>(){
            front = nullptr;
            back = nullptr;
        }

        bool is_empty(){
            return !front;
        }

        T peek_front(){
            return front->item;
        }

        T peek_back(){
            return back->item;
        }

        void enqueue(T item){
            Node<T>* heapNode = new Node<T>(item);
            if (this->is_empty()){
                front = heapNode;
                back = front;
            }
            else{
                back->nextNode = heapNode;
                back = heapNode;
            }
        }

        T dequeue(){
            T returnVal;
            if (front == back){
                returnVal = front->item;
                front = front->nextNode;
                back = front;
                return returnVal;
            }
            else{
                returnVal = front-> item;
                front = front->nextNode;
                return returnVal;
            }
        }

        ~Queue(){
            std::cout<<"--Deleting queue--";
            while(!this->is_empty()){
                Node<T>* curNode = front;
                front = front->nextNode;
                delete curNode;
            }
        }

};
#endif