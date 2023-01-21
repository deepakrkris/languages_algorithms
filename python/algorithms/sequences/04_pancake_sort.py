"""
 1, 3, 2
 2, 3, 1
 3, 2, 1
 1, 2, 3
 
 3, 4, 2, 1
 4, 3  2  1
 1, 2, 3, 4
 
 N = 4
 1, 5, 4, 3, 2
 5, 1, 4, 3, 2
 2, 3, 4, 1, 5
 N = 3
 4, 3, 2, 1, 5
 1, 2, 3, 4, 5
 N=2
 N=1
 N=0

"""
def pancake_sort(arr):
  N = len(arr) - 1
  
  def flip(arr, i) :
      lst = list(reversed(arr[0 : i + 1]))
      for j, n in enumerate(lst) :
        arr[j] = lst[j]

  while N > 0 :
      max_element = max(arr[0 : N + 1])
      K = arr[0 : N + 1].index(max_element)

      if K < N :
          flip(arr, K)
          flip(arr, N)
      N -= 1
  return arr

print(pancake_sort([1, 3, 1]))
print(pancake_sort([1, 5, 4, 3, 2]))
