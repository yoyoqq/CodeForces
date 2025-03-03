class Solution {
    public:
        vector<vector<int>> dp;
        int minCost(vector<int>& nums) {
            // map<int, int> cache;
            // return (int)calc(nums, 1, nums[0]);
            dp.resize(1001, vector<int>(1001, -1));
            return solve(nums, 1, 0);
        }
    
    private:
        int solve(vector<int>& nums, int i, int last){
            if (i+1 >= nums.size()) return max(nums[last], (i<nums.size() ? nums[i] : 0));
            if (dp[i][last] != -1) return dp[i][last];
            int res = max(nums[i], nums[i+1]) + solve(nums, i+2, last);
            res = min(res, max(nums[i], nums[last]) + solve(nums, i+2, i+1));
            res = min(res, max(nums[i+1], nums[last]) + solve(nums, i+2, i));
            return dp[i][last] = res;
        }
    
    
        int calc(vector<int>& nums, long long idx, long long last){
            if (idx >= nums.size()) return last;
            else if (idx+1 >= nums.size()) return max(nums[idx], nums[last]);
            // children
            long long ans = INT_MAX;
            long long a = last, b = idx, c = idx+1; 
            long long xy = max(nums[a], nums[b]) + calc(nums, idx+2, c);
            long long yz = max(nums[b], nums[c]) + calc(nums, idx+2, a);
            long long xz = max(nums[a], nums[c]) + calc(nums, idx+2, b);
            ans = max({ans, xy, yz, xz});
            return ans;
        }
    
    
        // int dp(vector<int>& nums, int idx){
        //     // base case 
        //     // only have 1 or two remaining 
        //     if (nums.size()-1 == idx){
        //         return nums[idx];
        //     }else if (nums.size()-2 == idx){
        //         return max(nums[idx], nums[idx+1]);
        //     }
        //     // children
        //     // xy, yz, xz
        //     int count = 1e9;
        //     int xy = max(nums[idx], nums[idx+1]) + dp(nums, idx+2);
        //     swap(nums[idx], nums[idx+2]);
        //     int yz = max(nums[idx+1], nums[idx+2]) + dp(nums, idx+2);
        //     swap(nums[idx], nums[idx+2]);
        //     swap(nums[idx+1], nums[idx+2]);
        //     int xz = max(nums[idx], nums[idx+2]) + dp(nums, idx+2);
        //     swap(nums[idx+1], nums[idx+2]);
        //     count = min({count, xy, yz, xz});
        //     cout << count << endl;
        //     return count;
        // }
    };