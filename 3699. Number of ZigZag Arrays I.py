class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        mod = 10**9 + 7
        r = r - l       # reset at 0 
        # dp[v] = number of zigzag arrays ending at value v 
        dp = [1] * (r+1)    
        # there are n operations 
        for i in range(1, n):     # start at 1, to count sz 1 arr
            # odd step, sum(dp[u]) for u < v 
            pre = 0
            if i % 2:
                # prefix sum 
                for v in range(r+1):
                    pre2 = pre + dp[v]      # for next pref
                    dp[v] = pre             # from previous pre 
                    pre = pre2 % mod 
            # even step, sum(dp[u]) for u > v 
            else:
                # suffix sum 
                for v in range(r, -1, -1):
                    pre2 = pre + dp[v]
                    dp[v] = pre
                    pre = pre2 % mod 
        # symmetry 
        return 2*sum(dp) % mod 

# class Solution:
#     def zigZagArrays(self, size: int, l: int, r: int) -> int:
#         MOD = 1e9 + 7

#         # TLE: how to speed up process
#         # pre/suffix sums -> how to use ?  
        

#         @cache
#         def dp(n, prev, dr):   # moves rem, prev num, direction
#             # base case
#             if n == 0: return 1
#             # dp 
#             ans = 0
#             if dr == False:
#                 for i in range(prev+1, r+1):
#                     ans = (ans + dp(n-1, i, True)) % MOD 
#             else:
#                 for i in range(l, prev):
#                     ans = (ans + dp(n-1, i, False)) % MOD 
#             # output
#             return ans
#         res = 0
#         for i in range(l, r+1):
#             res = (res + dp(size-1, i, True)) % MOD 
#             res = (res + dp(size-1, i, False)) % MOD
#         dp.cache_clear()
#         return int(res) 
        
