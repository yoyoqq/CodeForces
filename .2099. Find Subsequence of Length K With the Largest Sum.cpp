class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // take the max elements 
        vector<int> a = nums;
        sort(a.begin(), a.end());
        map<int, int> freq;
        // take off half smallest 
        for (int i=0; i<nums.size(); i++){dddddd
            freq[nums[i]]++;
        }
        for (int i=0; i<nums.size()-k; i++){
            freq[a[i]]--;
        }
        // only take the ones that are positive 
        vector<int> ans; 
        for (int i=0; i<nums.size(); i++){
            if (freq[nums[i]] > 0){
                freq[nums[i]]--;
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};