from shunting import Shunting
def main():
    equation = input('Enter an expression: ')
    infixList = Shunting.convertToInfix(equation).split(" ")
    print(infixList)
    print(f"Result ={Shunting.evaluate(infixList)}")

if __name__ == "__main__":
    main()