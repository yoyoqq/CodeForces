class Solution:
    def maxProduct(self, nums: List[int], k: int, limit: int) -> int:
        # do dp for every state 
        @cache
        def dp(idx, product, sm, is_positive, taken):
            if idx == len(nums):
                if product <= limit and sm == k and taken: 
                    return product
                return -1
                    
            return max(
                dp(idx+1, product, sm, is_positive, taken),
                dp(idx+1, min(limit+1, product*nums[idx]), sm + (is_positive * nums[idx]), -1* is_positive, 1))

        ans = dp(0, 1, 0, 1, 0)
        dp.cache_clear()
        return ans