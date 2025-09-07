import os
import sys
from collections import *

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    mn = a[0]
    for val in a:
        if mn * 2 <= val:
            print("NO")
            return
        mn = min(mn, val)
    print("YES") 
    
    # for i in a:
    #     mn = min(mn, i)

    # # print(a[-1], mn)
    # if a[-1] == mn:
    #     print("YES")
    # else:
    #     print("NO")


if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()