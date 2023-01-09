"""
Given an integer array and a window of size w, find the current maximum value in the window as it slides through the entire array.

Note: If the window size is greater than the array size, we consider the entire array as a single window.

Constraints:

1
1
 \leq
≤
 array.length \leq
≤
 10^3
10 
3
 

-10^4
−10 
4
 
 \leq
≤
 array[i] \leq
≤
 10^4
10 
4
 

1
1
 \leq
≤
 w


"""

def max_sliding_window(v, window_size) :
    result = []  
  
    start = 0
    end = window_size - 1

    while end < len(v) :
        result.append(max(v[start : end + 1]))
        start += 1
        end += 1

    return result


def main():
    v = [([1,2] , 2), ([1,2,3,4,5,6,7,8,9,10] , 3), ([3,3,3,3,3,3,3,3,3,3] , 4), ([10,6,9,-3,23,-1,34,56,67,-1,-4,-8,-2,9,10,34,67] , 2), ([9,5,3,1,6,3] , 2), ([4,5,6,1,2,3] , 1)]

    for i in range(len(v)) :
        print(i + 1, "  list : ", v[i][0], sep = '')
        print(i + 1, "  window size : ", v[i][1], sep = '')
        result = max_sliding_window(v[i][0], v[i][1])
        print("  max_sliding_window :", result)
        print("-"*100)

if __name__ == '__main__':
    main()
