class Solution {
    public:
            // what if we have a negative element 
            // prefix sum with sliding window ? 
        long long countSubarrays(vector<int>& nums, long long k) {
            int n = nums.size();
            // normal sliding window 
            long long count = 0, score = 0;
            int left = 0;
            for (int right=0; right<n; right++){
                score += nums[right];
                while (left < n && score * (right-left+1) >= k){
                    score -= nums[left];
                    left++;
                }
                // calculate 
                if (left <= right){
                    count += (right-left+1);
                }
                // cout << left << " " << right << endl;
            }
            return count;
        }
    };