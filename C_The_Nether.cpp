import os
import sys
from collections import *



for test in range(int(input)):
    n = int(input())
    a = int(input())
    # 
    # arr = [0] * n
    path = []       # output 
    layers = {}     # how many does each node have 
    big = -1
    for i in range(n):
        print(f"? {i+1} {n} {" ".join(list(map(str, list(range(1, n+1)))))}")
        sys.stdout.flush()
        ans = int(input())
        if ans in layers:
            layers[ans].append(i+1)
        else:
            layers[ans] = [i+1]  
        
        if big < ans:
            big = ans
            path = [i+1] 
    
    for depth in range(big-1, 0, -1):   # every time decrase -1 the depth, find the nodes and path that goes through 
        for candidate in layers[depth]:
            # is the candidate connected ? 
            print(f"? {path[-1]} 2 {path[-1]} {candidate}")
            sys.stdout.flush()
            ans = int(input())
            if ans == 2:
                path.append(candidate)
                break
    
    print(f"! {len(path)} {" ".join(list(map(str, path)))}")
    sys.stdout.flush()

