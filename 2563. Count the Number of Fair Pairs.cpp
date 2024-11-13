class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i=0; i<nums.size(); i++){
            // return index of lower bound
            auto it_lower = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            // return index of upper bound 
            auto it_upper = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            // [lower, upper)
            count += it_upper - it_lower;
        }
        return count;
    }

long long lower_bound(vector<int>& nums, int low, int high, int element){
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (nums[mid] >= element){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
};