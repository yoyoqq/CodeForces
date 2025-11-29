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
         

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sm = accumulate(nums.begin(), nums.end(), 0);
        return sm % k;
    }
};