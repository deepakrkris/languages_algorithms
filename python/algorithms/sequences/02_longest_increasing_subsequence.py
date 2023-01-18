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

    dp = [ 0 for _ in range(len(sequence)) ]

    for sub_seq_end in range(1, len(sequence)) :

        max_seq = 1

        for previous_seq_end in range(sub_seq_end) :
            if sequence[sub_seq_end] > sequence[previous_seq_end] :
                max_seq = max(max_seq , dp[previous_seq_end] + 1)
        
        dp[sub_seq_end] = max_seq

    return max(dp)

def main():
    test_data = [ [7, 12, 3, 8, 9, 4, 5, 6 ] , [ 6 , 4 , 8 , 5 , 7 ] ]

    for i in range(len(test_data)):
        print(i+1, ". \t Input data: ", test_data[i], sep="")
        seq_size = longest_increasing_subsequence(test_data[i])
        print("\t Output : ", seq_size)
        print("-"*97)

if __name__ == '__main__':
    main()
