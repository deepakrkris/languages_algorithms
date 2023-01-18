# Given a list of integers or list of integers, develop a iterator that can flatter a list
# [ 0, [ 0 ] ]
# [ [ [ 1 , 2, 3 ]  ]
# hasNext()
# next()
# [ 0, [0], 1]

class Iterator :
    def __init__(self, nested_list) :
        self.stack = []
        self.stack.append([nested_list , 0])

    def has_next(self) :
        # top[1] , top[0] = list , top[1] = ptr = 0
        # true
        # ptr = 1
        # stack len = 3 , ptr = 3
        # ptr = 1 , return 4
        # 
        if self.stack :
            top = self.stack[-1]
            lst = top[0]
            ptr = top[1]
            if ptr <= (len(lst) - 1) :
                return True
            else :
                self.stack.pop()
                return self.has_next()
        return False

    def next(self) :
        # stack len = 1
        # ptr = 2, stack len = 2 , top_ptr = 0
        # top_ptr 1. [ 1 , 2, 3 ]
        if self.has_next() :
            top = self.stack[-1]
            ptr = top[1]
            lst = top[0]
            if type(lst[ptr]) is list :
                top[1] += 1
                self.stack.append([ lst[ptr] , 0 ])
                return self.next()
            curr = lst[ptr]
            top[1] += 1
            return curr
        return None

it = Iterator([ 0, [ 1, [ 1 , [2, [3, 6, 9] ], 4] , 5 ]])
while it.has_next() :
    print(it.next())


"""        
it = Iterator([ 0, [0] ])

it = Iterator([ 0, [  [ 1 , 2, 3 ] ] ])
while it.has_next() :
    print(it.next())

it = Iterator([ 0, [  [ 1 , 2, 3 ] ] , 4 ])
while it.has_next() :
    print(it.next())
"""


