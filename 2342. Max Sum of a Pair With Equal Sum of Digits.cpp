class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            map<int, pair<int, int>> freq; 
            for (int i=0; i<nums.size(); i++){
                int cur = sum_digits(nums[i]);
                // first < second 
                if (nums[i] > freq[cur].second){
                    freq[cur].first = freq[cur].second;
                    freq[cur].second = nums[i];
                }
                else if (nums[i] > freq[cur].first){
                    freq[cur].first = nums[i];
                }
            }
            // get the max 
            int mx = -1;
            for (auto [k, v] : freq){
                if (v.first == 0) continue;
                mx = max(mx, v.first+v.second);
            }
            return mx;
        }
    
    private:
        int sum_digits(int num){
            int ans = 0;
            while (num){
                ans += num % 10;
                num /= 10;
            }
            return ans;
        }
    };