import os
import sys
from collections import *

def solve():
    n, k = map(int, input().split())
    s = input()
    
    ones = s.count("1")
    

    if ones <= k or n < 2*k:
        print("Alice")
    else:
    # elif ones > k and n >= 2 * k:
        print("Bob")
    # elif k == 1 and ones == 1:
    #     print("Alice")
    # elif k >= n//2 + n%2:
    #     print("Alice")
    # elif ones <= k:
    #     print("Alice")
    # else:
    #     print("Bob")
    


if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()