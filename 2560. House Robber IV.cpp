class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int left = *min_element(nums.begin(), nums.end()), right = *max_element(nums.begin(), nums.end()), n = nums.size();
            while (left <= right){
                int mid = left + (right - left) / 2;
                // check if we can with this mid 
                int i=0, count = 0;
                for (; i<n; i++){
                    if (nums[i] <= mid){
                        i++;
                        count++;
                    }
                }
                // if its possible, then reduce size  
                if (count >= k){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return left;
        }
    };