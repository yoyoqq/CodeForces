class Solution {
    public:
        long long mostPoints(vector<vector<int>>& questions) {
            // dp 
            // map<pair<int, long long>, long long> cache;
            // return dp(cache, questions, 0, 0LL);
    
            // reversed
            int n = questions.size();
            vector<long long> dp(n, 0);
            dp[n-1] = questions[n-1][0];
            for (int i=n-2; i>=0; i--){
                int points = questions[i][0], brainpower = questions[i][1];
                // take or skip 
                long long next = brainpower+i+1 < dp.size() ? dp[brainpower+i+1] : 0;
                dp[i] = max(dp[i+1], points + next);
                // cout << dp[i+1] << " " << points << " " << next << endl;
            }
            // for (int i=0; i<n; i++){
            //     cout << dp[i] << " ";
            // }
            return dp[0];
        }
                               
    private:
        long long dp(map<pair<int, long long>, long long>& cache, vector<vector<int>>& questions, int idx, long long power){
            if (idx >= questions.size()) return power;
            if (cache.find({idx, power}) != cache.end()) return cache[{idx, power}];
            // take or skip
            long long points = dp(cache, questions, idx+1, power);
            points = max(points, dp(cache, questions, idx+questions[idx][1]+1, power+questions[idx][0]));
            return points;
        }
    };