class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            // count unique nums
            set<int> unique;
            for (int& x : nums) unique.insert(x);
            // sliding window 
            int count = 0;
            int right = 0, cur_unique = 0;
            map<int, int> freq;
            for(int left=0; left<n; left++){
                // move window 
                right = max(left, right);
                while (right < n && cur_unique < unique.size()){
                    freq[nums[right]]++;
                    if (freq[nums[right]] == 1) cur_unique++;
                    right++;
                }
                // output, count the whole subarray till the end
                if (cur_unique == unique.size()){
                    cout << left << " " << right << endl;
                    count += (n - right + 1);
                }
                // move left 
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) cur_unique--;
            }
            return count;
        }
    };