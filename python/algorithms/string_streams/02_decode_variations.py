"""
1262
1 26 2
12 6 2
1 2 6 2

12     ->  1
1 2    ->  1

1262
1 -> 1
2 -> 2
6 -> 2
2 -> 3

def parse(S, i) :
    if i == len(S) :
        return 0

    if i > 0 and int(S[i - 1]) > 0 and int(S[i - 1]) < 3 :
        return parse(S, i + 1) + 1
    elif int(S[i]) > 0 and int(S[i]) < 3:
        return parse(S, i + 1) + 1
    else :
        return 0
"""

def decodeVariations(S):
    dp = [0 for _ in range(len(S) + 1)]

    def valid_first_digit(c) :
        return int(c) > 0 and int(c) < 3 

    for i in range(1, len(S) + 1) :
        if i > 1 and valid_first_digit(S[i - 2]) and valid_first_digit(S[i - 1]):
           dp[i] = dp[i - 1] + 1
        elif i > 1 and valid_first_digit(S[i - 2]) :
           dp[i] = dp[i - 1] 
        elif valid_first_digit(S[i - 1]) :
           dp[i] = dp[i - 1] + 1
        elif i > 1 :
           dp[i] = dp[i - 2]
        else :
           return 0

    return dp[len(S)]

print(decodeVariations('1262'))
print(decodeVariations('111'))
print(decodeVariations('117'))
print(decodeVariations('17'))
print(decodeVariations('1'))
print(decodeVariations('7'))
print(decodeVariations('12177'))
