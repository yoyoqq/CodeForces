import os
import sys
from collections import *
from typing import *

class Solution:
    def maxWeight(self, n: int, edges: List[List[int]], k: int, t: int) -> int:
        # brute force ? 
        # 300 * 300 
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))
        
        
        # node, cur_sum, visited
        @cache
        def dfs(cur_node, cur_sum, cur_k):
            # base case 
            if cur_k == 0:
                # print(cur_sum, t)
                if cur_sum < t: 
                    return cur_sum
                return -1
            
            ans = -1
            for next_node, next_w in graph[cur_node]:
                ans = max(ans, dfs(next_node, cur_sum+next_w, cur_k-1))
            return ans

        res = -1
        for i in range(0, n):
            res = max(res, dfs(i, 0, k))
        return res

# if os.getenv("ONLINE_JUDGE") is None:
#     sys.stdin = open("input.txt", "r")
#     sys.stdout = open("output.txt", "w")
# for ___ in input():
#     print(Solve.solve())


# n = 3
# edges = [[0,1,1],[1,2,2]]
# k = 2
# t = 4



# n = 3
# edges = [[0,1,2],[0,2,3]]
# k = 1
# t = 3

# n = 3
# edges = [[0,1,6],[1,2,8]]
# k = 1
# t = 6

# # print(Solution.maxWeight(n, edges, k, t))
# sol = Solution()
# a = sol.maxWeight(n, edges, k, t)
# print(a)