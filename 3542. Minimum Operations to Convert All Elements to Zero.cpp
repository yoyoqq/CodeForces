from collections import *
from typing import *

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        a = []
        for num in nums:
            if not a or num != a[-1]:
                a.append(num)
        # print(arr)
        
        stack = []  # monotonic increasing stack 
        count = 0
        for num in a:
            # if empty, take all and start over 
            if num == 0:
                count += len(stack)
                stack.clear()
            else:
                # if decreasing remove 
                seen = set()
                while stack and stack[-1] > num:
                    seen.add(stack[-1])
                    stack.pop()
                count += len(seen)
                if not stack or stack[-1] < num:
                    stack.append(num)
                
        # print(stack)
        return count + len(stack)
        # return count + len(seen)
        
        
        
        # count = len(a)
        # n = len(a)
        # # decrease by the number of peaks 
        # for i in range(a):
            
        
        
        
        # for i in range(len(arr)):
            # if i and i != len(arr)-1 and arr[i-1] < arr[i] > arr[i+1]:
                
        
        # return 0
        # freq = defaultdict(int)
        # for num in arr:
        #     freq[num] += 1
        #     count += 1
        
        # mx = 0
        # for k, v in freq.items():
        #     mx = max(mx, v)
        
        # print(count, mx)
        # return count - mx + 1
        
        
        
# nums = [1,2,1,2,1,2]
# nums = [1,2,3,2,1]
# nums = [1,2,3,2,1,2,3,2,1]
# sol = Solution()
# print(sol.minOperations(nums))
