class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // bulid pref 
        int n = nums.size();
        vector<long long> pref(n+1);
        for (int i=1; i<=n; i++){
            pref[i] = nums[i-1] + pref[i-1];
        }
        // calculate valid splts 
        int splits = 0;
        for (int i=0; i<n-1; i++){
            long long left = pref[i+1];
            long long right = pref[n] - pref[i+1];
            if (left >= right) splits++;
        }
        return splits;
    }
};