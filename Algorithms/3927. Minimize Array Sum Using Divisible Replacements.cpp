class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long ans = 0;
        map<int, int> freq;
        int mx = 0;
        for (int& num : nums) {
            mx = max(mx, num);
            freq[num]++;
        }
        // algo 
        for (auto& [k, v] : freq) {
            if (v == 0) continue;       // replaced it already 
            for (int b=k; b<=mx; b+=k) {
                ans += (1LL * freq[b] * k);
                freq[b] = 0;
            }
        }
        return ans;
    }
};