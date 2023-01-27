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
    accumulator = 0
    operand = 0
    op_multiply = False
    sign = 1

    for c in expression :
        if c.isdigit() :
            operand = operand * 10 + int(c)
        elif c == "+" :
            if op_multiply :
                accumulator *= operand * sign
                sign *= 1
                operand = 0
                op_multiply = False
            else :
                operation_stack.append(accumulator)
                sign = 1
                accumulator = operand
                operand = 0
        elif c == '*' :
            if op_multiply :
                accumulator *= operand * sign
                sign = 1
                operand = 0
            else :
                operation_stack.append(accumulator)
                sign = 1
                accumulator = operand
                operand = 0
            op_multiply = True
        elif c == "-" :
            sign = sign * -1

    if op_multiply :
        accumulator *= operand * sign
        operation_stack.append(accumulator)
    else :
        accumulator += operand * sign
        operation_stack.append(accumulator)

    print(operation_stack)
    return sum(operation_stack)

def main():
    input = (
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
