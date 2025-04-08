class Solution {
    public:
        int minimumPairRemoval(vector<int>& nums) {
            // min sum (leftmost one)
            // replace by their sum 
            int ans = 0;
            // brute force, find if sorted 
            while (true){
                bool is_sorted = true;
                int mn_sum = 1e9;
                int idx = -1;
                for (int i=1; i<nums.size(); i++){
                    if (nums[i-1] > nums[i]) is_sorted = false;
                    if (nums[i] + nums[i-1] < mn_sum){
                        mn_sum = min(mn_sum, nums[i] + nums[i-1]);
                        idx = i-1;
                    }
                }
                if (is_sorted || nums.size() <= 1) break;
                // put to new vector, use mn_sum 
                vector<int> a;
                for (int j=0; j<nums.size(); j++){
                    // append both together 
                    if (j == idx){
                        a.push_back(mn_sum);
                        j++;
                    }else{
                        a.push_back(nums[j]);
                    }
                }
                nums = a;
                ans++;
                for (int k=0; k<nums.size(); k++) cout << nums[k] << " "; cout << endl;
            }
            return ans;
        }
    };