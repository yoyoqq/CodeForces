class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // SLIDING WINDOW 
        int left = 0;
        int mn_len = INT_MAX;
        int xr = 0;
        vector<int> bitCounts(32, 0);
        for (int right=0; right<nums.size(); right++){
            updateBitCounts(bitCounts, nums[right], 1);
            while (left <= right && convertBitCounts(bitCounts) >= k){
                mn_len = min(mn_len, right - left + 1);
                updateBitCounts(bitCounts, nums[left], -1);
                left++;
            }
        }
        return mn_len == INT_MAX ? -1 : mn_len;

        // // NEEDS TO BE A SUBARRAY !!
        // // greedy? sort, one one freq of each num
        // // from biggest to smallest till >= k
        // sort(nums.begin(), nums.end());
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // for (int i=1; i<nums.size(); i++){
        //     if (nums[i-1] != nums[i]) temp.push_back(nums[i]);
        // }
        // // find xor >= k
        // int xr = 0;
        // int count = 0;
        // for (int i=temp.size()-1; i>=0; i--){
        //     xr = xr | temp[i];
        //     count++;
        //     if (xr >= k) return count; 
        // }
        // return -1;
    }
private:

    void updateBitCounts(vector<int>& bitCounts, int number, int delta){
        for (int bit=0; bit<32; bit++){
            if ((number >> bit) & 1){
                bitCounts[bit] += delta;
            }
        }
    }

    int convertBitCounts(const vector<int>& bitCounts){
        int res = 0;
        for (int bit=0; bit<32; bit++){
            if (bitCounts[bit] != 0){
                res = res | 1 << bit;
            }
        }
        return res;
    }
};