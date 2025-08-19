class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD = 1e9 + 7

        for l, r, k, v in queries:
            idx = l
            while idx <= r:
                nums[idx] = (nums[idx] * v) % MOD
                idx += k

        # print(nums)
        ans = 0
        for num in nums:
            ans = ans ^ int(num)
        return ans
