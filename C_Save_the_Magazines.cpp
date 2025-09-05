import os
import sys
from collections import *

def solve():
    n = int(input())
    s = list(map(int, input()))
    a = list(map(int, input().split()))
    
    s = [0] + s
    a = [0] + a
    
    ans = 0
    i = 0
    while i <= n:
        mn = a[i] 
        sm = a[i]
        j = i + 1
        while j <= n and s[j] != 0:
            mn = min(mn, a[j])
            sm += a[j]
            j += 1
        ans += sm - mn 
        i = j

    print(ans)
    
    
    # print(n, s, a)
    # return 
    # for i in range(1, n):
    #     if s[i] == 1 and s[i-1] == 0:
    #         if a[i-1] >= a[i]:
    #             s[i-1] = 1
    #             s[i] = 0
    #         elif i+1<n and s[i+1] == 1 and a[i-1] >= a[i+1] and a[i] >= a[i+1]:
    #             s[i-1] = 1
    #             s[i] = 0
                

    # count = 0
    # for i in range(n):
    #     if s[i] == 1:
    #         count += a[i]

    # # print(count, n, s, a
    # print(count)
        
    


if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()