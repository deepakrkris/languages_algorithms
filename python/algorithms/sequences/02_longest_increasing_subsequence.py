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

    dp = [ ]

    for num in sequence :
   
        longest_seq_until_i = [ num ]

        for seq in dp :
            if seq[-1] < num :
                new_seq = seq +  [ num ]

                if len(longest_seq_until_i) < len(new_seq) :
                    longest_seq_until_i = new_seq

        dp.append(longest_seq_until_i)

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
