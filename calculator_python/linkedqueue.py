'''
Author: Henry Michael Hoopes
KUID: 3037626
Date: 2/8/23
Lab: lab03
Last modified: 2/8/23
Purpose: This file defines the LinkedQueue object, with functions to enable a user to interact 
with the queue and its member variables.
'''
from node import Node
class LinkedQueue:
    def __init__(self):
        '''Initializes the queue with no front and no back'''
        self.front = None
        self.back = None

    def isEmpty(self):
        '''Returns a boolean representing if the queue is empty'''
        return self.front == None

    def peek_front(self):
        '''If the queue isn't empty, returns front value. Otherwise, raises RuntimeError'''
        if not self.isEmpty():
            return self.front.value
        else:
            raise RuntimeError("Cannot peek on empty queue!")

    def enqueue(self, entry):
        '''Places the entry value at the back of the queue'''
        entryNode = Node(entry)
        if not self.isEmpty():
            self.back.next = entryNode
            self.back = entryNode
        else:
            self.front = entryNode
            self.back = self.front

    def dequeue(self):
        '''Removes and Returns the front entry, unless queue is empty. If queue is empty, raise an error'''
        if self.isEmpty():
            raise RuntimeError("Cannot dequeue on an empty queue")
        elif self.front == self.back:
            temp = self.front.value
            self.front = self.front.next #should be none
            self.back = self.front #should be none
            return temp
        else:
            temp = self.front.value
            self.front = self.front.next
            return temp
        
    def __str__(self):
        cur_node = self.front
        returnStr = ""
        while(cur_node is not None):
            returnStr += str(cur_node)
            cur_node = cur_node.next
        return returnStr
