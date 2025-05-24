import os
import sys
from collections import *
from typing import * 


class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        # the tree doesnt matter 
        # find the longest branch 
        # dp for count sum either 1 or 2 
        # brute force -> either one or two at each level 
        # smart dp  ?  O(n) 
        
        # 1. count the lenght of the path 
        graph = defaultdict(list)
        for x, y in edges:
            graph[x].append(y)
            graph[y].append(x)
        # 2. bfs find longest path 
        bfs = [[1,0]]  # cur_node, parent
        levels = -1
        while bfs:
            size = len(bfs)
            temp = []
            for _ in range(size):
                node, parent = bfs.pop()
                for neigh in graph[node]:
                    if neigh != parent:
                        temp.append([neigh, node])
            bfs = temp
            # print(bfs)
            levels += 1
        
        # print(graph)
        # print("levels ", levels)
        # return 0
        
        # 3. get dp for each combination 
        # pattern just increases by * 2 every time 
        # 1 2 4 8 .. 
        # make tree of decision choises 1 or 2 
        MOD = 10 ** 9 + 7
        # ans = 1
        # for _ in range(1, levels)/:
        #     ans = (ans * 2) % MOD
        return (1 << (levels-1)) % MOD
        # print(ans) 
        # dp = [0] * levels
        # dp[0] = 1
        # print(levels, dp)
        # for i in range(levels):
            
    

# sol = Solution()
# print(sol.assignEdgeWeights([[1,2]]))
# print(sol.assignEdgeWeights([[1,2],[1,3],[3,4],[3,5]]))