import os
import sys

def solve():
    a, b = map(int, input().split())
    xk, yk = map(int, input().split())   
    xq, yq = map(int, input().split())

    s = [-1, 1]
    king = set()
    queen = set()

    for sx in s:
        for sy in s:
            king.add((xk + sx * a, yk + sy * b))
            king.add((xk + sx * b, yk + sy * a))

            queen.add((xq + sx * a, yq + sy * b))
            queen.add((xq + sx * b, yq + sy * a))

    print(len(king & queen))

if os.path.exists("input.txt"):
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")

t = int(input())
for _ in range(t):
    solve()