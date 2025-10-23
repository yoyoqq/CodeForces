#define ll long long;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        // to remove cur position 
        map<int, int> freq;
        for(int& x : nums) freq[x]++;
        
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int& num : nums){
            for (int cur : {num-k, num, num+k}){
                int left = lower_bound(nums.begin(), nums.end(), 1LL*cur-k) - nums.begin();
                int right = upper_bound(nums.begin(), nums.end(), 1LL*cur+k) - nums.begin();
                int dist = right - left;

                // cur frequency + can use from sides 
                ans = max(ans, freq[cur] + min(numOperations, dist-freq[cur]));
            }
        }
        return ans;
    }
};