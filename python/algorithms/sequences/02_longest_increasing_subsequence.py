"""
Given an integer array, nums, return the length of the longest strictly increasing subsequence.

Constraints:

1 \leq
1≤
 nums.length \leq 2500
≤2500
-10^4 \leq
−10 
4
 ≤
 nums[i] \leq 10^4
≤10 
4


[ 7, 12, 3, 8, 9, 4, 5, 6 ] 

 
6  4  8  5  7
0  0  1  1  2
   0  1  1  2
      0  1  2 
         1  2 
"""

def longest_increasing_subsequence(sequence) :

    dp = [ [] ]

    for i in range(len(sequence)) :
        for seq in dp :
            if not seq or seq[-1] < sequence[i] :
                new_seq = seq +  [ sequence[i] ]
                dp.append(new_seq)

    return max([ len(s) for s in dp ])

def main():
    test_data = [ [7, 12, 3, 8, 9, 4, 5, 6 ] , [ 6 , 4 , 8 , 5 , 7 ] ]

    for i in range(len(test_data)):
        print(i+1, ". \t Input data: ", test_data[i], sep="")
        seq_size = longest_increasing_subsequence(test_data[i])
        print("\t Output : ", seq_size)
        print("-"*97)

if __name__ == '__main__':
    main()
