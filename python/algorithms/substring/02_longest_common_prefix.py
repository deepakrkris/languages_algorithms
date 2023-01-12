def longestCommonPrefix(strs) :
    min_len = float('inf')
    short_word = ""
    for s in strs :
        if len(s) < min_len :
            short_word = s
            min_len = len(short_word)

    for index in range(len(short_word)) :
        for s in strs :
            if short_word[index] != s[index] :
                return short_word[ : index]
    
    return short_word

print(longestCommonPrefix([ "abcabc" , "abc", "abcdeffedcba", "abcbdaefxabcdef" ]))
