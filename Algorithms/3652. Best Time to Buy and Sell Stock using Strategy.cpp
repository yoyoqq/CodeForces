class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        # prefix with sum to delete 
        n = len(prices)
        pref = [0] * (n+1)  # take off with it later on 
        psum = [0] * (n+1)  # prefix sum of all being strat[i] == 1
        total = 0
        for i, price in enumerate(prices):
            pref[i+1] = pref[i] + (prices[i] * strategy[i] * -1)
            psum[i+1] = psum[i] + abs(prices[i])
            total += prices[i] * strategy[i]
        
        ans = total
        for i in range(n-k+1):
            erase = pref[i+k] - pref[i]
            strat = psum[i+k] - psum[i+k//2] # half empty, half sell
            ans = max(ans, total + erase + strat)
        return ans