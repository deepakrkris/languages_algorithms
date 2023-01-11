from typing import List

def findRepeatedDnaSequences(s: str) -> List[str]:
    seen = {}
    result = {}

    for index in range(9, len(s)) :
        substr = s[index - 9 : index + 1]
        if substr in seen and substr not in result:
            result[substr] = True
        seen[substr] = True
    
    return list(result.keys())

print(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"))
print(findRepeatedDnaSequences("AAAAAAAAAAAAA"))
