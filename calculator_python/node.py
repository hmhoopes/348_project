'''
Author: Henry Michael Hoopes
KUID: 3037626
Date: 2/1/23
Lab: lab02
Last modified: 2/1/23
Purpose: This file defines the node object.
'''
class Node:
    def __init__(self, value):
        '''Initialize Node object with value and no next'''
        self.value = value
        self.next = None

    def __str__(self):
        '''Return a string representation of Node object'''
        return f"{self.value} "
