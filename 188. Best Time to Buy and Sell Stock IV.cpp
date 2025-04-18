class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, 0)));
            for (int i=n-1; i>=0; i--){
                for (int t=1; t<=k; t++){
                    // not holding -> take max from right || from holding
                    dp[i][t][0] = max(dp[i+1][t][0], -prices[i] + dp[i+1][t][1]);
                    // holding -> not sell or sell (dec k)
                    dp[i][t][1] = max(dp[i+1][t][1], prices[i] + dp[i+1][t-1][0]);
                }
            }
            return dp[0][k][0];         // start at 0, k transactions, not holding
        }
    };


    
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