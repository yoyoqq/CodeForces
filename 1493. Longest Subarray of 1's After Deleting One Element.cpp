class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // sliding window -> only one zero on it 
        int zeroes = 0, ones = 0, left = 0, ans = 0;
        bool is_zero = false;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == 1) ones++;
            else {
                zeroes++;
                is_zero = true;
            }
            // move the window ? 
            while (left <= i && zeroes > 1){
                if (nums[left] == 1) ones--;
                else zeroes--;
                left++;
            }
            ans = max(ans, ones);
        }
        return ans - (is_zero == false ? 1 : 0);
    }
};


// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         // 1. group by count of 1s 
//         // 2. left right pointer reset if 00 
//         bool is_zero = false;
//         int ans = 0;
//         int left = 0, right = 0;
//         // bool deleted = false;
//         for (int i=0; i<nums.size(); i++){
//             // left/right pointer 
//             if (nums[i] == 1){
//                 if (is_zero == false) left++;
//                 else right++;
//             }
//             // its 0 
//             else{
//                 if (is_zero)
//                     left = right;
//                 right = 0;
//                 if (i && nums[i-1] == 0){
//                     left = 0;
//                     right = 0;
//                 }
//                 is_zero = true;
//             }
//             // cout << i << " " << left << " " << right << endl;
//             ans = max(ans, left + right);
//         }
//         return ans - (is_zero == false ? 1 : 0);
//     }
// };