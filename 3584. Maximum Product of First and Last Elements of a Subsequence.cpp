class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;
        long long ans = LLONG_MIN;
        for (int i=m-1; i<nums.size(); i++){
            mn = min(mn, 1LL * nums[i-m+1]);
            mx = max(mx, 1LL * nums[i-m+1]);
            ans = max({ans, nums[i] * mn, nums[i] * mx});
        }
        return ans;
    }
};


class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        map<int, int> freq; // store min and max val
        for (int& num : nums) freq[num]++;

        // mantain a window of size m 
        long long ans = LLONG_MIN;
        int j = 0;
        for (int i=0; i<nums.size()-m+1; i++){
            while (j-i+1 != m){
                freq[nums[j]]--;
                if (freq[nums[j]] == 0) freq.erase(nums[j]);
                j++;
            }
            // if pos get pos 
            if (nums[i] >= 0){
                ans = max(ans, 1LL * nums[i] * freq.rbegin()->first);
                // cout << nums[i] << " " << freq.rbegin()->first << endl;
            }
            // if neg get min 
            else{
                ans = max(ans, 1LL * nums[i] * freq.begin()->first);
                // cout << nums[i] << " " << freq.begin()->first << endl;
            }
        }
        return ans;
    }
};