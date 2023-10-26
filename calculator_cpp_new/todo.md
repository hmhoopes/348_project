# Todo 
- [X] Exponent calculation  
- [X] modulo calculation 
- [X] Unary operators 
- [ ] Check Test cases 
- [ ] Refactor

# Test Cases 
## Valid Expressions
- [X] 1. Addition: 3 + 4
- [X] 2. Subtraction with Parentheses: 8 - (5 - 2)
- [X] 3. Multiplication and Division: 10 * 2 / 5
- [X] 4. Exponentiation: 2 ^ 3
- [X] 5. Mixed Operators: 4 * (3 + 2) % 7 - 1
- [X] 6. Complex Addition with Extraneous Parentheses: (((2 + 3))) + (((1 + 2)))
- [X] 7. Mixed Operators with Extraneous Parentheses: ((5 * 2) - ((3 / 1) + ((4 % 3))))
- [X] 8. Nested Parentheses with Exponents: (((2 ^ (1 + 1)) + ((3 - 1) ^ 2)) / ((4 / 2) % 3))
- [X] 9. Combination of Extraneous and Necessary Parentheses: (((((5 - 3))) * (((2 + 1))) + ((2 * 3))))
- [X] 10. Extraneous Parentheses with Division: ((9 + 6)) / ((3 * 1) / (((2 + 2))) - 1)
  - There is troublt here with the last minus, program thinks it is a unary operator 
- [X] 11. Combining Unary Operators with Arithmetic Operations: +(-2) * (-3) – ((-4) / (+5)) 
- [X] 12. Unary Negation and Addition in Parentheses: -(+1) + (+2)
- [X] 13. Negation and Addition with Negated Parentheses: -(-(-3)) + (-4) + (+5)
  - trouble here with parenthesis 
- [X] 14. Unary Negation and Exponentiation: +2 ^ (-3)
- [X] 15. Combining Unary Operators with Parentheses: -(+2) * (+3) - (-4) / (-5) 

## Invalid Expressions
  - not showing unmatched parentheses error 
- [X] 1. Unmatched Parentheses: 2 * (4 + 3 - 1
- [ ] 2. Operators Without Operands: * 5 + 2
  - Not showing operator without operand error 
- [X] 3. Incorrect Operator Usage: 4 / 0 
- [ ] 4. Missing Operator: 5 (2 + 3)  
  - not give an error at all (answer is outputted as 5) 
- [X] 5. Invalid Characters: 7 & 3
- [X] 6. Mismatched Parentheses: (((3 + 4) - 2) + (1)
- [X] 7. Invalid Operator Usage: ((5 + 2) / (3 * 0))
  - division by zero
- [ ] 8. Invalid Operator Sequence: ((2 -) 1 + 3)
- [ ] 9. Missing Operand: ((4 * 2) + ( - ))
- [X] 10. Invalid Characters: ((7 * 3) @ 2) 
