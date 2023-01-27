"""
Given a string containing an arithmetic expression,
implement a basic calculator that evaluates the expression string.
The expression string can contain integer numeric values and
should be able to handle the “+” and “-” operators, as well as “()” parentheses.

1   +2*3
1   2   3   1
  +   *   +
"""

def calculator(expression) :
    operation_stack = []
    operand_stack = []
    operand = 0
    sign = 1

    for c in expression :
        if c.isdigit() :
            operand = operand * 10 + int(c)
        elif c == "+" :
            if operation_stack and operation_stack[-1] == '*' :
                operand_stack.append(operand * sign)
                sign = 1
                operand = 0
            while operation_stack and operation_stack[-1] == '*' :
                print(operation_stack, operand_stack)
                operation_stack.pop()
                operand1 = operand_stack.pop()
                operand2 = operand_stack.pop()
                operand_stack.append(operand1 * operand2)
            operand_stack.append(operand)
            operand = 0
        elif c == '*' :
            operation_stack.append('*')
            operand_stack.append(operand * sign)
            sign = 1
            operand = 0
        elif c == "-" :
            sign = sign * -1

    if operation_stack and operation_stack[-1] == '*' :
        operand_stack.append(operand * sign)
        sign = 1
        operand = 0

    while operation_stack and operation_stack[-1] == '*' :
        operation_stack.pop()
        operand1 = operand_stack.pop()
        operand2 = operand_stack.pop()
        operand_stack.append(operand1 * operand2)

    operand_stack.append(operand * sign)
    return sum(operand_stack)

def main():
    input = (
             "1+2",
             "1+2*32",
             "1+2*16*2",
             "1+2*16*2+1",
             "1+2*16*2+1*3",
             "3",
             "1+-2*32",
             "1+2*16*-2",
             "1+2*16*2+-1",
             "1+2*-16*2+1*3",
            )

    num = 1
    for i in input:
        print(num, ".", "\tGiven Expression: ", i)
        print("\tThe result is: ", calculator(i))
        num += 1
        print("-"*20)

main()
