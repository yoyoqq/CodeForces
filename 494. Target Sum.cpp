class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        dp(nums, target, count, 0, 0);
        return count;
    }

private:
    void dp(vector<int>& nums, int& target, int& count, int cur, int idx){
        // base case
        if (idx == nums.size()){
            if (target == cur){
                count++;
            }
            return;
        }
        // children     
        dp(nums, target, count, cur - nums[idx], idx+1);
        dp(nums, target, count, cur + nums[idx], idx+1);
    }
};



class Solution {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(nums.size(), vector<int>(2 * totalSum + 1, INT_MIN));
        return dp(memo, nums, target, 0, 0);
    }

private:
    int dp(vector<vector<int>>& memo, vector<int>& nums, int& target, int cur, int idx){
        // base case
        if (idx == nums.size()){
            if (target == cur){
                return 1;
            }
            return 0;
        }
        if (memo[idx][cur + totalSum] != INT_MIN) {
            return memo[idx][cur + totalSum];
        }
        // children  
        int count = 0;
        count += dp(memo, nums, target, cur - nums[idx], idx+1);
        count += dp(memo, nums, target, cur + nums[idx], idx+1);
        memo[idx][cur + totalSum] = count;
        return count;
    }
};