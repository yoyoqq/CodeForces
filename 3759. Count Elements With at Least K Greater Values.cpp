class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (k == 0) return nums.size();
        map<int, int> freq;
        for (int& num : nums) freq[num]++;
        // count it 
        int count = nums.size();
        int ans = 0;
        for (auto& [kk, v] : freq){
            count -= v;
            if (count - k >= 0){
                ans += v;
            }
        }
        return ans;
    }
};