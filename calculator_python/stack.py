'''
Author: Henry Michael Hoopes
KUID: 3037626
Date: 2/1/23
Lab: lab02
Last modified: 2/1/23
Purpose: This file defines the stack object with the push, pop, peek, and isEmpty functions.
'''
from node import Node

class Stack:
    def __init__(self):
        '''Initialize stack object with no top value'''
        self._top = None

    def push(self, entry):
        '''Set the top value to entry and set the current top to point to the last top'''
        entry_node = Node(entry)
        entry_node.next = self._top
        self._top = entry_node

    def pop(self):
        '''Return the top value and set the top value to what it points to. Raises an RuntimeError if the stack is empty'''
        temp = self._top 
        if temp == None:
            raise RuntimeError("Stack is empty!")
        else:
            self._top = self._top.next
            return temp.value
    
    def peek(self):
        '''Return the top value. Raises an RuntimeError if the stack is empty'''
        if(self.is_empty()):
            raise RuntimeError("Stack is empty!")
        else:
            return self._top.value

    def is_empty(self):
        '''Return if the stack is empty'''
        return self._top == None
    
    def __str__(self):
        cur_node = self._top
        returnStr = ""
        while(cur_node is not None):
            returnStr += str(cur_node)
            cur_node = cur_node.next
        return returnStr