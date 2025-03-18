class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            // brute force is max O(30)
            int n = nums.size(), ans = 0;
            for (int i=0; i<n; i++){
                int nice = 0;
                int count = 0;
                for (int j=i; j<min(n, i+30); j++){
                    if ((nice & nums[j]) != 0) break;
                    nice = nice | nums[j];
                    count++;
                }
                ans = max(ans, count);
            }
            return ans;
        }
    };


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