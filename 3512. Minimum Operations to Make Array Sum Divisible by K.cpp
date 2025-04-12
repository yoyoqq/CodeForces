"""
1. nums[i] = nums[i] - 1
2. sum() % k == 0

5
3 9 7 => 19 % 5 

4 1 3 => 8 
  
"""

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(nums) % k 
         