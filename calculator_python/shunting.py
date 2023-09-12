from linkedqueue import LinkedQueue
from stack import Stack
import math
class Shunting:
    def convertToInfix (expression):
        out_queue = LinkedQueue()
        op_stack = Stack()
        expList = list(expression.strip())
        levelDict = {
            "+" : 1,
            "-" : 1,
            "*" : 2,
            "/" : 2,
            "^" : 3

        }
        iterator = 0
        for elem in expList:
            iterator += 1
            #could be switch statement
            if elem == " ":
                continue

            #if its beginning parantheses or a carat(has weird rules)
            elif elem == "(" or elem == "^":
                op_stack.push(elem)

            #pops until it reaches the end parantheses
            elif elem == ")":
                while not (op_stack.is_empty()):
                    top = op_stack.pop()
                    if top == "(":
                        break
                    else:
                        out_queue.enqueue(top)

            #if its in the keys
            elif elem in levelDict.keys():
                while not (op_stack.is_empty()):
                    #checks top elem w/o removing
                    top = op_stack.peek()
                    #here incase top is a parantheses
                    if top not in levelDict.keys():
                        break
                    #here so that anything on the stack greater than or equal to current is added to out 
                    if levelDict[top] >= levelDict[elem]:
                        out_queue.enqueue(op_stack.pop())
                    #here so that it ends breaks if the top is in level dict but not >= than current elem
                    else:
                        break
                op_stack.push(elem)

            #adds it to the infix queue
            else:
                out_queue.enqueue(elem)
            
        #after everything has been checked, add remaining operators to the infix queue
        while not (op_stack.is_empty()):
            out_queue.enqueue(op_stack.pop())
        return str(out_queue)
    
    def evaluate(infixList):
        numStack = Stack()
        opDict = {
            "+" : 1,
            "-" : 1,
            "*" : 2,
            "/" : 2,
            "^" : 3
        }
        for elem in infixList:
            if elem in opDict.keys():
                rightNum = numStack.pop()
                leftNum = numStack.pop()
                if elem == "+":
                    result = float(leftNum) + float(rightNum)
                if elem == "-":
                    result = float(leftNum) - float(rightNum)
                if elem == "/":
                    result = float(leftNum) / float(rightNum)
                if elem == "*":
                    result = float(leftNum) * float(rightNum)
                if elem == "^":
                    result = math.pow(float(leftNum), float(rightNum))

                print(f"{leftNum} {elem} {rightNum} = {result}")
                numStack.push(result)
            else:
                numStack.push(elem)

        return str(numStack)
            