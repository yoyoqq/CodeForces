class Solution {
    public:
        const int MOD = 1e9 + 7;
        map<pair<int, int>, int> cache;
        
        int numTilings(int n) {
            // fibonnacci seqeunce 
            // 1 2 5 11 24 53 117 258 .. 
            // prev1 * 2 + prev3
            // if (n == 1) return 1;
            // if (n == 2) return 2;
            // if (n == 3) return 5;
            // queue<int> q; 
            // q.push(1);
            // q.push(2);
            // q.push(5);
            // for (int i=4; i<n; i++){
            //     int cur = ((q.back() * 2)%MOD + q.front()) % MOD;
            //     q.pop();
            //     q.push(cur);
            // }
            // return ((q.back() * 2)%MOD + q.front()) % MOD;
            
            return dp(0, n, false);
            
            // 1   
            // 2 
            // 3 -> +2 
            // vector<long> dp(n+1, 0);
            // dp[0] = 1;
            // for (int i=1; i<=n; i++){
            //     if (i-1 >= 0) dp[i] = (dp[i] + dp[i-1]) % MOD;
            //     if (i-2 >= 0) dp[i] = (dp[i] + dp[i-2]) % MOD;
            //     if (i-3 >= 0) dp[i] = (dp[i] + (dp[i-3] * 2) % MOD);
            // } 
            // for (auto& x : dp) cout << x << " "; cout << endl;
            // return dp[n];
        }
    
    private:
        int dp(int i, int n, bool possible){    // possible is if used 3 
            if (i > n) return 0;
            if (i == n) return !possible;
            int cur_count = 0;
            // cur_count = (cur_count + dp(n, idx+1)) % MOD;
            // cur_count = (cur_count + dp(n, idx+2)) % MOD;
            // cur_count = (cur_count + dp(n, idx+3)*2) % MOD;
            // can be more than 1 2 3 operations, check at 3 1 1 1 3 for example (draw it out)
    
            // used 3 ? keep using or close 
            if (possible){
                return (dp(i+1, n, false) + dp(i+1, n, true) % MOD);
            }
            return (dp(i+1, n, false) + dp(i+2, n, false) + 2L*dp(i+2, n, true)) % MOD;
            
            return cur_count;
        }
    };