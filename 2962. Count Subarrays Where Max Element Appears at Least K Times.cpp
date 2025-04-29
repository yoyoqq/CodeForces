class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            int mx = maxi(nums), mx_count = 0;
            long long count = 0;
            int right = 0;
            for (int left=0; left<n; left++){
                // right = max(left, right);
                // move the left, to break subarray 
                while (right < n && mx_count < k){
                    if (nums[right] == mx) mx_count++;
                    right++;
                }
                // output
                if (mx_count == k) count += (n - right + 1);
                // new window 
                if (nums[left] == mx) mx_count--;
    
            }
            return count;
        }
    
    private:
        int maxi(vector<int>& nums){
            int mx = 0;
            for (int& num : nums) mx = max(mx, num);
            return mx;
        }
    };