import os
import sys
from collections import *

class Solution:
    def maxSubstrings(self, word: str) -> int:
        # sliding window find 
        # greedy whenver found take 
        # as we need to take as many as possible, waiting will decrease the result 

        pos = defaultdict(int)  # save the last position
        count = 0
        for i in range(len(word)):
            char = word[i]
            # 4 char long
            if char in pos and i - pos[char] + 1 >= 4:
                count += 1
                pos.clear()
            # new char? 
            elif char not in pos:
                pos[char] = i
            
        return count


# if os.getenv("ONLINE_JUDGE") is None:
#     sys.stdin = open("input.txt", "r")
#     sys.stdout = open("output.txt", "w")
# for x in input():
# print(Solution.maxSubstrings("abcdeafdef"))
# print(Solution.maxSubstrings("bcdaaaab"))

# sol = Solution()
# print(sol.maxSubstrings("abcdeafdef"))
# print(sol.maxSubstrings("bcdaaaab"))
