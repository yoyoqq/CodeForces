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



class Solution {
public:
    // backtracking, maths, string manipulation, bit mask 
    // only need the lenght for each
    // dp

    const int MOD = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> values = {low, high, zero, one};
        map<int, int> memo;
        return (dp(values, memo, zero) + dp(values, memo, one)) % MOD;
    }

    // store the values on the arr -> size for each 
    int dp(vector<int>& values, map<int, int>& memo, int num){
        int count = 0;
        if (num > values[1]) return 0;
        if (memo.find(num) != memo.end()) return memo[num];
        // valid 
        if (values[0] <= num && num <= values[1]){
            count = (count + dp(values, memo, num + values[2]) + dp(values, memo, num + values[3]) + 1) % MOD;
        }
        else{
            count = (count + dp(values, memo, num + values[2])) % MOD;
            count = (count + dp(values, memo, num + values[3])) % MOD;
        }
        memo[num] = count;
        return count;
    }
};