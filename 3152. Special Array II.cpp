class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pref(n, 0);
        for (int i=1; i<n; i++){
            if (nums[i-1] % 2 == nums[i] % 2){
                pref[i]++;
            }
            pref[i] = pref[i] + pref[i-1];
        }

        vector<bool> ans;
        for (auto& q : queries){
            if (pref[q[0]] != pref[q[1]]){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};