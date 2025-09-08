import os
import sys
from collections import *

def solve():
    a = input()
    b = input()
    if len(a) > len(b):
        a, b = b, a
    
    match = ""
    for i in range(len(a)-1):
        for j in range(len(b)-1):  
            if a[i:i+2] == b[j:j+2]:
                match = a[i:i+2]
                break
    
    if a[0] == b[0]:
        print("YES")
        print(a[0] + "*")
    elif a[-1] == b[-1]:
        print("YES")
        print("*" + a[-1])
    elif len(match):
        print("YES")
        print("*" + match + "*")
    else:
        print("NO")
        
if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

intput_size = int(input())    
for ___ in range(intput_size):
    solve()    