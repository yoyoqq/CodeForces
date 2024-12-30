class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[0] = 1;
        for (int h=1; h<=high; h++){
            if (h >= zero)
                dp[h] += dp[h-zero];
            if (h >= one)
                dp[h] += dp[h-one];
            dp[h] = dp[h] % (int)(1e9+7);
        }
        int ans = 0;
        for (int i=low; i<=high; i++){
            // cout << dp[i] << " ";
            ans += dp[i];
            ans %= (int)(1e9+7);
        }
        return ans;
    }
};