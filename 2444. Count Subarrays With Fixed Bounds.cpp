class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n = nums.size();
            long long count = 0;
            int mn = -1, mx = -1;
            int left = 0;
            for (int i=0; i<n; i++){
                // if the subarray is not possible move the pointer left 
                if (!(minK <= nums[i] && nums[i] <= maxK)){
                    left = i + 1;
                    continue;
                }
                // calculate new mx mn 
                if (minK == nums[i]) mn = i;
                if (maxK == nums[i]) mx = i;
                // from leftmosts to poss window to take all subarrays 
                count += max(0, min(mn, mx) - left + 1);
            }
    
            return count;
        }
    };
    
    
    // class Solution {
    // public:
    //     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    //         // sliding window ? 
    //         // suffix for min/max 
    //         int n = nums.size();
    //         nums.push_back(1e9);
    //         vector<int> min_suff(n+1, n+1);
    //         for (int i=n-1; i>=0; i--){
    //             min_suff[i] = min_suff[i+1];
    //             if (nums[min_suff[i]] > nums[i+1]){
    //                 min_suff[i] = i+1;
    //             }
    //         }
    //         nums[n] = 0;
    //         vector<int> max_suff(n+1, n+1);
    //         for (int i=n-1; i>=0; i--){
    //             max_suff[i] = max_suff[i+1];
    //             if (nums[max_suff[i]] < nums[i+1]){
    //                 max_suff[i] = i + 1;
    //             }
    //         }
    //         // sliding window 
    //         long long count = 0;
    
    //         for (int left=0, right=0; left<n; left++){
    //             right = max(left, right);
    //             while (right < n && ){
                    
    //             }
    //         }
    
    //         return count;
    //     }
    // };