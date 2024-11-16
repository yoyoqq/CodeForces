class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // if (nums.size() == 1) return {nums[0]};
        if (k == 1) return nums;
        vector<int> powers; 
        int n = nums.size();
        for (int i=0; i<n-k+1; i++){
            int mx = 0; 
            // k increasing elements
            for (int j=i; j<i+k-1; j++){
                if (nums[j] - nums[j+1] != -1){
                    mx = -1;
                    break;                    
                }
                mx = max(mx, nums[j+1]);
                // cout << nums[j] << " " << nums[j+1] << "  ";
            }
            powers.push_back(mx);
            // cout << endl;
        }
        return powers;
    }
};