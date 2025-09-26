class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums = sorted(nums)
        n = len(nums)
        ans = 0
        for i in range(n):
            for j in range(i+1, n):
                k = bisect_left(nums, nums[i]+nums[j])-1
                if j < k:
                    ans += (k-j)
        return ans
