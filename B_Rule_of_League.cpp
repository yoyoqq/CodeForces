import os
import sys
from collections import *

def solve():
    n, x, y = map(int, input().split())

    mn = min(x, y)
    mx = max(x, y)
    
    if mn != 0 or mx == 0: 
        print(-1)
        return

    # mistmatch on mx ? can we use 
    times = (n-1) // mx
    if times * mx != n-1:
        print(-1)
        return
    arr = []
    cur = 1 
    for i in range(1, times+1):
        for j in range(mx):
            arr.append(cur)
        cur = i * mx + 2
    print(*arr)
    
    
    # if x > y:
    #     x, y = y, x
    
    # if x == 0:
    #     if y == 0:
    #         print(-1)
    #     elif y == 1:
    #         for i in range(n-1):
    #             print(i+1, " ")
    #     elif (n-1) % y == 0:
    #         arr = []
    #         cur = 1
    #         for i in range((n-1)//y):
    #             for j in range(y):
    #                 # print(i+1, " ")
    #                 arr.append(cur)
    #             cur += (y+1)
    #         print(*arr)
    #     else:
    #         print(-1)
        
    # elif x == 1:
    #     if y == 1:
    #         for i in range(n-1):
    #             print(i+1, " ")
    #     else:
    #         print(-1)
    # else:
    #     print(-1)
    


if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()