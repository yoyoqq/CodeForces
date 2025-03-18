class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            // && for all pairs == 0
            // max arr 
            // sliding window -> if !=, xor for left pointer  
            // else || 
            int left = 0, n = nums.size();
            int ans = 0;
            int cur = 0;
            for (int right=0; right<n; right++){
                // not possible move left
                // cur | nums[right] & nums[left]  
                while ((cur & nums[right]) != 0){
                    cur = cur ^ nums[left];
                    left++;
                }
                cur = cur | nums[right];
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };