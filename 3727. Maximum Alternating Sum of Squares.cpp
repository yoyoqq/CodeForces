class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // max min max min ... 
        for (int& num : nums) {
            if (num < 0) num = num * -1;
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int left = nums[j] * nums[j];
            int right = nums[i] * nums[i]; 
            ans = ans + (left - right);
            i++; 
            j--;
        }
        if (nums.size() % 2 == 1) {
            ans += nums[i] * nums[i];
        }
        return ans;
    }
};