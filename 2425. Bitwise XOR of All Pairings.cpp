class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // property of xor -> x ^ x = 0
        int xr2 = 0;
        for (int num : nums2){
            xr2 ^= num;
        }
        // calculate for each num in nums1
        int count = 0;
        for (int num : nums1){
            if (nums2.size() % 2 == 0){
                count ^= xr2;
            }else{
                count = count ^ xr2 ^ num;
            }
        }
        return count;
    }
};