class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            int n= nums.size();
            vector<int> a(n, 0);
            for (int i=0; i<n; i++){
                a[i] = nums[nums[i]];
            }
            return a;
        }
    };