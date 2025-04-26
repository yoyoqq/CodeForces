class Solution:
    def baseUnitConversions(self, conversions: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(conversions)
        dp = [0] * (n+1)
        dp[0] = 1
        for i in range(n):
            source = conversions[i][0]
            target = conversions[i][1]
            factor = conversions[i][2]
            # print(source, target, factor)
            # dp 
            dp[target] = (dp[target] + (dp[source] * factor) % MOD) % MOD 
            # print(dp)
        return dp;