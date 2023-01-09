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


"""

def longest_increasing_subsequence(sequence) :

    def check_increase_seq(max_so_far , index) :
        if index == len(sequence) :
            return 0

        max_seq_len = 0

        if max_so_far is None or sequence[index] > max_so_far :
            max_seq_len = check_increase_seq(sequence[index], index + 1) + 1

        max_seq_len = max (max_seq_len, check_increase_seq(max_so_far, index + 1))

        return max_seq_len

    return check_increase_seq(None, 0)

def main():
    test_data = [ [7, 12, 3, 8, 9, 4, 5, 6 ] ]

    for i in range(len(test_data)):
        print(i+1, ". \t Input data: ", test_data[i], sep="")
        seq_size = longest_increasing_subsequence(test_data[i])
        print("\t Output : ", seq_size)
        print("-"*97)

if __name__ == '__main__':
    main()
