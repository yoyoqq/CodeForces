import os
import sys
from collections import *

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    freq = Counter(a)

    for k, v in freq.items():
        if v % 2 == 1:
            print("YES")
            return
    print("NO")
    
    # key = max(list(freq.keys()))
    # print(key)
    # return 
    # if freq[key] % 2 == 1:
    #     print("YES")
    # # elif n % 2 == 1:
    # #     print("YES")
    # else:
    #     print("NO")


if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()