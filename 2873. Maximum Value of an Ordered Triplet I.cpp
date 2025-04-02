class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            // for O(n) O(n)
            int n = nums.size();    
            vector<int> left(n);    // (i-j)
            vector<int> right(n);   // k
            // for left (i-k)
            int mx = nums[0];
            for (int i=1; i<n-1; i++){
                left[i] = mx - nums[i];
                mx = max(mx, nums[i]);
            }
            // for right the max, get the max number from its right 
            for (int i=n-2; i>=0; i--){
                right[i] = max(right[i+1], nums[i+1]);
            }
            long long ans = 0; 
            for (int i=0; i<n; i++){
                ans = max(ans, 1LL * left[i] * right[i]);
            }
            return ans;
        }
    };