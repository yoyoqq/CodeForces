class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        // prefix suffix 
        map<int, int> left;
        map<int, int> right;
        int n = nums.size();
        for (int i=0; i<n; i++){
            right[nums[i]]++;
        }
        // count triplets
        const int MOD = 1e9 + 7;
        long ans = 0;
        for (int i=0; i<n; i++){
            int mid = nums[i];
            right[mid]--;
            // count triplet 
            int l = left[mid*2];
            int r = right[mid*2];
            ans = (ans + ((long)l * r) % MOD) % MOD;
            left[mid]++;
        }
        return (int)ans;
    }
};