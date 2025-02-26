class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int ans = 0;
            int mn = 0;     // sum of all, if positive -> 0
            int mx = 0;     // sum of all, if negative -> 0
            int cur_sum = 0;    
            for (int num : nums){
                cur_sum = max(0, cur_sum + num);
                mx = max(0, abs(cur_sum));
                mn = min(0, num+mn);
                ans = max({ans, mx, abs(mn)});
                // cout << mx << " " << mn << endl;
            }
            return ans;
        }
    };