"""
You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
You may change 0's to 1's to connect the two islands to form one island. Return the smallest number of 0's you must flip to connect the two islands.
     1,1,0
     1,0,0
     0,0,1
"""

from collections import deque

def find_distance(Q, grid) :
    while Q :
        new_Q = deque()
        while Q :
            new_Q.appendleft(Q.pop())

        while new_Q :
            [current_row, current_col] = new_Q.pop()

            current_distance = grid[current_row][current_col]

            if current_row + 1 < len(grid) and grid[current_row + 1][current_col] != 2 :
                if grid[current_row + 1][current_col] == 1 :
                    return current_distance
                if grid[current_row + 1][current_col] == 0 :
                    grid[current_row + 1][current_col] = current_distance + 1
                    Q.appendleft([ current_row + 1, current_col])
            if current_row - 1 >= 0  and grid[current_row - 1][current_col] != 2 :
                if grid[current_row - 1][current_col] == 1 :
                    return current_distance
                if grid[current_row - 1][current_col] == 0 :
                   grid[current_row - 1][current_col] = current_distance + 1
                   Q.appendleft([ current_row - 1 , current_col])
            if current_col + 1 < len(grid[0]) and grid[current_row][current_col + 1] != 2 :
                if grid[current_row][current_col + 1] == 1 :
                    return current_distance
                if grid[current_row][current_col + 1] == 0 :
                    grid[current_row][current_col + 1] = current_distance + 1
                    Q.appendleft([ current_row, current_col + 1])
            if current_col - 1 >= 0 and grid[current_row][current_col - 1] != 2:
                if grid[current_row][current_col - 1] == 1 :
                    return current_distance
                if grid[current_row][current_col - 1] == 0 :    
                    grid[current_row][current_col - 1] = current_distance + 1
                    Q.appendleft([ current_row, current_col - 1])

def shortest_bridge(grid) :
    Q = deque()

    def paint(i , j) :
        if i < 0 or j < 0 :
            return
        if i >= len(grid) or j >= len(grid[0]) or grid[i][j] == 0 :
            return
        if grid[i][j] == 2 :
            return

        grid[i][j] = 2
        Q.appendleft([i, j])
        paint(i + 1, j)
        paint(i - 1, j)
        paint(i, j + 1)
        paint(i, j - 1)


    def find_first_bridge() :
        for i in range(len(grid)) :
            for j in range(len(grid[0])) :
                if grid[i][j] == 1 :
                    return paint(i, j)

    find_first_bridge()
    distance = find_distance(Q, grid) - 2

    return distance


test_data = [
    [[0,1,0],[0,0,0],[0,0,1]],
    [
     [1,1,1,1,1],
     [1,0,0,0,1],
     [1,0,1,0,1],
     [1,0,0,0,1],
     [1,1,1,1,1]
    ],
    [
     [1,1,0,0,1],
     [1,0,0,0,1],
     [1,0,0,0,1],
     [1,0,0,0,1],
     [1,0,0,1,1],
    ]
]

def print_grid(grid) :
    for r in grid :
        print('\t' , r)

for i, t in enumerate(test_data) :
    print(i + 1, '\t', " test data is ")
    print_grid(t)
    print('\t', 'result is', shortest_bridge(t))
    print_grid(t)
    print('_' * 20)
