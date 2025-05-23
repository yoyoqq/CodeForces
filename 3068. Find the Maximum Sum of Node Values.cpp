class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int c = 1 << 30, swap = 0;
        for (int a : nums){
            int b = a ^ k;          // use xor ? 
            res += max(a, b);       // add to res 
            swap = swap ^ (a < b);  // if swap odd use at the end 
            c = min(c, abs(a-b));   // get min value to take off 
        }   
        // res - swap if odd
        return res - swap * c; 
    }
};