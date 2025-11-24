class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n, false);
        int cur = 0;
        for (int i=0; i<n; i++){
            cur = (cur << 1) + nums[i];
            cur = cur % 5;
            if (cur % 5 == 0) ans[i] = true;
            // cout << cur << endl;
        }
        return ans;
    }
};