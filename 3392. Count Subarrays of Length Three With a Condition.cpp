class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for (int i=2; i<nums.size(); i++){
            int one = nums[i-2];
            int two = nums[i-1];
            int three = nums[i];
            // cout << one + three<< " " << two / 2 << endl;
            if (two % 2 == 0 && (one + three == two / 2)){
                count++;
            }
        }
        return count;
    }
};