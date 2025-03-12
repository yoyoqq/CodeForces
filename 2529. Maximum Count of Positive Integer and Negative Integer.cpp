class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            // bin search
            // positive -> leftbound 1 
            // negative -> rightbound -1 
            int pos_idx = nums.size() - (int)(lower_bound(nums.begin(), nums.end(), 1) - nums.begin());
            int neg_idx = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
            cout << pos_idx << " " << neg_idx << endl;
            return max(pos_idx, neg_idx);
            // return 0;
        }
    };
    
    
    // class Solution {
    // public:
    //     int maximumCount(vector<int>& nums) {
    //         // two ways 
    //         // 1. linear search
    //         // 2. bin search >= 1 ,  >= -1
    //         int pos = 0, neg = 0;
    //         for(int num : nums){
    //             if (num >= 1) pos++;
    //             else if (num <= -1) neg++;
    //         }
    //         return max(pos, neg);
    //     }
    // };