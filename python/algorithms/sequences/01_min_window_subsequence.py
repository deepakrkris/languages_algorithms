"""

Given strings str1 and str2, find the minimum (contiguous) substring sub_str of str1, such that every character of str2 appears in sub_str in the same order as it is present in str2.

If there is no window in str1 that covers all characters in str2, return an empty string.

If there are multiple minimum-length windows, return the one with the leftmost starting index.

Constraints:

1
1
 \leq
≤
 str1.length \leq
≤
 2 \times 10^3
2×10 
3
 

1
1
 \leq
≤
 str2.length \leq
≤
 100
100

str1 and str2 consist of uppercase and lowercase English letters.



"""

def min_window(str1, str2) :
    min_match = ""
    min_window_size = float('inf')

    for start, _ in enumerate(str1) :
        str1Index = start
        str2Index = 0

        while str1Index < len(str1) and str2Index < len(str2) :
            if str1[str1Index] == str2[str2Index] :
                str2Index += 1
            str1Index += 1

        if str2Index == len(str2) :
            if min_window_size > str1Index - start :
                min_window_size = str1Index - start
                min_match = str1[start : str1Index]

    return min_match, min_window_size


def main():
    str1 = ["abccdebdde", "fgrqsqsnodwmxzkzxwqegkndaa",
            "qwewerrty", "aaabbcbq", "zxcvnhss", "alpha",
            "beta", "asd", "abcd"]
    str2 = ["bde", "kzed", "wer", "abc",
            "css", "la", "ab", "as", "pp"]

    for i in range(len(str1)):
        min_match, min_size = min_window(str1[i], str2[i])
        print(i+1, ". \t Input string: (" + str1[i]+", " + str2[i]+")", sep="")
        print("\t min_match : ", min_match)
        print("\t min_size  : ", min_size)
        print("-"*97)

if __name__ == '__main__':
    main()
