class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)

        @cache
        def dp(idx, transaction_left, holding):
            # base case
            if idx == n or transaction_left == 0:
                return 0

            # skip
            res = dp(idx+1, transaction_left, holding)
            # buy 
            if (holding == False):
                res = max(res, -prices[idx] + dp(idx+1, transaction_left, True))
            # sell  
            elif (holding == True):
                res = max(res, prices[idx] + dp(idx+1, transaction_left-1, False))

            return res    
        
        return dp(0, k, False)