"""
Given a string containing an arithmetic expression,
implement a basic calculator that evaluates the expression string.
The expression string can contain integer numeric values and
should be able to handle the “+” and “-” operators, as well as “()” parentheses.

   3, -1
"""

def calculator(expression) :
    sign = 1
    operands = "+-"
    operation_stack = []
    accumulator = 0
    operand = 0

    for c in expression :

        if c.isdigit() :
            operand = operand * 10 + int(c)
        elif c in operands :
            accumulator += operand * sign

            operand = 0
            sign = 1
            if c == '-' :
                sign = -1

        elif c == '(' :
            operation_stack.append(accumulator)
            operation_stack.append(sign)
            accumulator = 0
            sign = 1
        elif c == ')' :
            accumulator += operand * sign
            operand = 0
            sign = 1
            sign = operation_stack.pop()
            accumulator =  sign * accumulator
            accumulator += operation_stack.pop()

    return accumulator + (operand * sign)

def main():
    input = (
             "4 + (52 - 12) + 99",
             "(31 + 7) - (5 - 2)",
             "(12 - 9 + 4) + ( 7 - 5)",
             "8 - 5 + (19 - 11) + 6 + (10 + 3)",
             "56 - 44 - (27 - 17 - 1) + 7"
            )

    num = 1
    for i in input:
        print(num, ".", "\tGiven Expression: ", i)
        print("\tThe result is: ", calculator(i))
        num += 1
        print("-"*20)

main()
