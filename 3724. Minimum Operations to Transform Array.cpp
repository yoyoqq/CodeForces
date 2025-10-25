class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size();
        int mn = 1e9;    // closest to nums2.back() ? 
        for (int i=0; i<n; i++){
            ans += abs(nums1[i] - nums2[i]);
            mn = min({mn, abs(nums1[i] - nums2.back()), abs(nums2[i] - nums2.back())});
            if (min(nums1[i], nums2[i]) <= nums2.back() && nums2.back() <= max(nums1[i], nums2[i])){
                mn = 0;
            }
        }
        return ans + mn + 1;
    }
};