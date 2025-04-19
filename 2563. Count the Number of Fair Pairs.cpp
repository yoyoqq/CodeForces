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


class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            // 3       6 
            // -2 -1 0 1 4 4 5 7
            // l     r       sliding window  
            //              greedy ? dp ?  
            //     2 2 2    sort -> BS -> count in range
            // l -> lower - num[i]  lower_bound     find leftmost that can take 
            // r -> upper - num[i]  upper_bound     find rightmostthat can take 
            // in order not to recount pairs again, left pointer -> i + 1 
            int n = nums.size();
            sort(nums.begin(), nums.end());
            // for (int i=0; i<n; i++) cout << i << " "; cout << endl;
            // for (int i=0; i<n; i++) cout << nums[i] << " "; cout << endl;
    
            long long count = 0;
            for (int i=0; i<n; i++){
                int l = lower - nums[i];
                int r = upper - nums[i];
                int l_upper = lower_bound(nums.begin()+i+1, nums.end(), l) - nums.begin();
                int r_lower = upper_bound(nums.begin()+i+1, nums.end(), r) - nums.begin();
                // cout << i << " " << l << " " << r << " " << l_upper << " " << r_lower << " " << (r_lower - l_upper) << endl;
                count += r_lower - l_upper;
            }
            return count;
        }
    };