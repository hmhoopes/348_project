#ifndef NODE_H
#define NODE_H
template <typename T>
class Node{
    public:
        T item;
        Node<T>* nextNode;
        Node(T entry){
            nextNode = nullptr;
            item = entry;
        };
};
#endif  