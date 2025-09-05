import os
import sys
from collections import *

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    # if odd then it is impossible to make it 
    # simplify by looking at the pairs 
    if n % 2 != 0:
        print(-1)
        return

    out = []
    for i in range(0, n, 2):
        if a[i] == a[i+1]:
            out.append((i+1, i+2))
        else:
            out.append((i+1, i+1))
            out.append((i+2, i+2)) 
    
    print(len(out))
    for x, y in out:
        print(x, y)
    
        
    # pos = 0
    # neg = 0
    # for i in a:
    #     if i == 1: pos += 1
    #     else: neg += 1 
    
    # i = 0
    # out = []
    # while i+1 < n and pos != neg:
    #     # reduce pos with 1 1 
    #     if pos > neg and 1 == a[i] == a[i+1]:
    #         i += 2 
    #         pos -= 1
    #     elif pos < neg and -1 == a[i] == a[i-1]:
    #         i += 2
    #         neg -= 1
    #     else:
    #         i += 1
    #         out.append(i+1)

    # # not possible 
    # if len(a) == 1:
    #     print(-1)
    #     return
    # # print output 
    # print(len(out))
    


intput_size = int(input())    
for ___ in range(intput_size):
    solve()