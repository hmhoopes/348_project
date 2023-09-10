#include <iostream>
#include "stack.h"
#include "queue.h"
int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    while (!s.is_empty()){
        std::cout<<s.pop()<<"\n";
    }

    std::cout<<"---Queue time---\n";
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout<<"added all vals to queue\n";

    while (!q.is_empty()){
        std::cout<<q.dequeue()<<"\n";
    }

    return(0);
}