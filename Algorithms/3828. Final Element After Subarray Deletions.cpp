class Solution {
public:
    int finalElement(vector<int>& nums) {
        // max min 
        // intuition -> best to do, both will only do one move to go against the other move 
        // 1 9 3    on mid  
        // 1 2 3 4  on left 
        // 4 3 2 1  on right 
        // only care about ONE NUM 
        return max(nums[0], nums[nums.size()-1]);
    }
};