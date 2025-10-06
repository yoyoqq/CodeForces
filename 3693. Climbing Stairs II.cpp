class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        // current position
        for(int i=0; i<=n; i++){
            for (int j=i; j<min(n, i+3); j++){
                int cost = costs[j] + (j-i+1)*(j-i+1);
                dp[j+1] = min(dp[j+1], dp[i] + cost);
            }
            // for (int& x : dp) cout << x << " "; cout << endl;
        }
        return dp[n];
    }
};
