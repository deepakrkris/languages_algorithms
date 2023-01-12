"""
Find the length of the longest non-repeating character substring of a string

Source string: abcabc
Substring: abca, abc, ab, a
Substring without repeating characters: abc, ab, a
Longest substring without repeating characters: abc
Return result: 3

    i
abc abc
 ^   ^

bac abc
  ^ ^ 
max_len = 3
start = 0  
a : 2

start = 1
b : 1
c : 1
a : 1
end = 3

"""

def longest_unique_substring(str) :
    last_seen = {}
    start = 0
    max_len = 0

    # start = 0
    # index = 3
    for index in range(len(str)) :
        c_at_index = str[index]
        
        #  { a : 0 , b : 1 : , c : 2 } 
        #  c_at_index = a
        if c_at_index in last_seen and last_seen[c_at_index] >= start :
            # start = 1
            start = last_seen[c_at_index] + 1
        
        last_seen[c_at_index] = index
        max_len = max(max_len, index - start + 1)
    
    return max_len
        

print(longest_unique_substring("abcabc"))
print(longest_unique_substring("bacabc"))
print(longest_unique_substring("abcdeffedcba"))
print(longest_unique_substring("abcbdaefxabcdef"))
