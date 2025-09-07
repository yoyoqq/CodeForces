import os
import sys
from collections import *

def solve():
    # print("-----")
    n = int(input())
    d = list(map(int, input().split()))
    a = [d[0]]
    for i in range(1, n):
        x = abs(d[i] + a[-1])
        y = abs(d[i] - a[-1])
        # print(x, y, d, x-a[i-1], y-a[i-1])
        if x != y and d[i] == abs(x - a[i-1]) and d[i] == abs(y - a[i-1]):
            print(-1)
            return
        a.append(x)
        
    print(*a)
    
    


if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()