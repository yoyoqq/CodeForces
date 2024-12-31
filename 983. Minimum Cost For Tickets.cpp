class Solution {
public:
    int dp(vector<int>& days, vector<int>& costs, map<pair<int, int>, int>& memo, int days_idx, int cur){
        // base case
        if (days.size() <= days_idx){
            return cur;
        }
        if (memo.find({days_idx, cur}) != memo.end()) {
            return memo[{days_idx, cur}];
        }
        int ans = INT_MAX;
        // one day 
        ans = min(ans, dp(days, costs, memo, days_idx+1, cur+costs[0]));
        // 7 days, jump 7 days from cur pos 
        int jumps7 = days_idx;
        while (jumps7 < days.size() && days[jumps7] - days[days_idx] < 7){
            jumps7++;
        }
        ans = min(ans, dp(days, costs, memo, jumps7, cur+costs[1]));
        // 30 days 
        int jumps30 = days_idx;
        while (jumps30 < days.size() && days[jumps30] - days[days_idx] < 30){
            jumps30++;
        }
        ans = min(ans, dp(days, costs, memo, jumps30, cur+costs[2]));
        // output
        memo[{days_idx, cur}] = ans;
        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<pair<int, int>, int> memo;
        return dp(days, costs, memo, 0, 0);
        
        // // get dp 
        // int size = days.back();
        // vector<int> dp(size+1, 0);
        // // use costs 
        // for (int day=1; day<dp.size(); day++){  // for each day
        //     dp[day] = dp[day-1] + costs[0];
        //     dp[day] = min(dp[day], dp[max(0, day-7)] + costs[1]);
        //     dp[day] = min(dp[day], dp[max(0, day-30)] + costs[2]);
        // }
        // for (auto x : dp){
        //     cout << x << " " ;
        // }
        // return dp[size-1];
    }
};