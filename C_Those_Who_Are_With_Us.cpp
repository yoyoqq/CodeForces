import os
import sys
from collections import *

def solve():
    n, m = map(int, input().split())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))

    mx = max(max(row) for row in matrix)
    times = 0 
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == mx:
                times += 1
    
    
    cols = [0 for _ in range(m)]
    rows = [0 for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == mx:
                rows[i] += 1
                cols[j] += 1

    flag = False
    for i in range(n):
        for j in range(m):
            if rows[i] + cols[j] - (matrix[i][j] == mx) == times:
                flag = True
                
    print(mx - flag)

    # for i in range(n): 
    #     row = 0
    #     col = 0
    #     for j in range(m):
    #         if matrix[i][j] == mx:
    #             if i == j:
    #                 row += 1
    #             else:
    #                 row += 1
    #                 col += 1
    #         if row + col == times:
    #             print(mx-1)
    #             return
    # print(mx)
                


    # max = -1
    # second_max = -1
    # for i in range(n):
    #     for j in range(m):
    #         if matrix[i][j] > max:
    #             second_max = max
    #             max = matrix[i][j]
    #         elif matrix[i][j] > second_max and matrix[i][j] != max:
    #             second_max = matrix[i][j]
    
    # # mark the rows and cols which have max
    # rows = [0 for _ in range(n)]
    # cols = [0 for _ in range(m)]
    # for i in range(n):
    #     for j in range(m):
    #         if matrix[i][j] == max:
    #             rows[i] += 1
    #             cols[j] += 1
    
    # # delete the rows and cols which have max
    # for j in range(m):
    #     temp_rows = rows[:]
    #     temp_cols = cols[:]
    #     for i in range(n):  # delete the vals  
    #         if matrix[i][j] == max:
    #             temp_rows[i] -= 1
    #             temp_cols[j] -= 1
    #     # check if there is any row or col which has max
    #     # temp_rows needs to be all all 0 and only one max 
    #     # temp_cols need to be zero after the take off in temp_rows 
    #     print(temp_rows, temp_cols)
    #     # take it off from rows, only 1 should be marked at max  
    #     times = 0
    #     row_idx = -1
    #     for i in range(len(temp_rows)):
    #         row_val = temp_rows[i]
    #         if row_val > 0:
    #             row_idx = i
    #             times += 1
    #     if times >= 2:
    #         continue
    #     # try to take off from the col itself 
    #     for col_idx in range(m):
    #         if matrix[row_idx][col_idx] == max:
    #             temp_cols[col_idx] -= 1
    #             temp_rows[row_idx] -= 1 
    #     print(temp_rows, temp_cols)
    #     print()
    #     if all(x == 0 for x in temp_rows) and all(x == 0 for x in temp_cols):
    #         print(second_max)
    #         return

    # print(max)
    
    
if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()