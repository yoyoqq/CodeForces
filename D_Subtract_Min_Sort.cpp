import os
import sys
from collections import *

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    
    for i in range(1, n):
        mn = min(a[i], a[i-1])
        a[i] -= mn
        a[i-1] -= mn
    
    for i in range(1, n):
        if a[i-1] > a[i]:
            print("NO")
            return
    print("YES")


if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()