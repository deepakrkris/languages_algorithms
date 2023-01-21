"""
Implement a document scanning function wordCountEngine, which receives a string document
and returns a list of all unique words in it and their number of occurrences, sorted by
the number of occurrences in a descending order. If two or more words have the same count,
they should be sorted according to their order in the original sentence. Assume that all
letters are in english alphabet. You function should be case-insensitive, so for instance,
the words “Perfect” and “perfect” should be considered the same word.
"""

def word_count_engine(para) :
    frequencies = {}
    special_chars = "!?&.'\""
    current_word = ""

    for c in para :
        if c not in special_chars and c != " " and c != '\t' :
            current_word += c.lower()
        elif c == " " or c == '\t' :
            if len(current_word) > 0 :
                if current_word not in frequencies :
                    frequencies[current_word] = 1
                else :
                    frequencies[current_word] += 1
            current_word = ""
    
    if current_word not in frequencies :
        frequencies[current_word] = 1
    else :
        frequencies[current_word] += 1
    
    counts = [ [ k, frequencies[k] ] for k in frequencies ]
    counts.sort( key=lambda x : x[1] , reverse=True )

    return counts

def main():
    input = [ "Practice makes perfect. you'll only get Perfect by practice. just practice!" ]
    num = 1
    for i in input:
        print(num, ".", "\tGiven Para : ", i)
        print("\tThe result is: ", word_count_engine(i))
        num += 1
        print("-"*20)

main()
