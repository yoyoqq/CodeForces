#define ll long long

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // prefix 
        vector<ll> pref(n+1, 0);
        for (int i=0; i<n; i++){
            pref[i+1] = pref[i] + nums[i];
        }
        ll ans = LONG_MIN;
        for (int i=0; i<k; i++){        // index to start 
            ll cur = 0;            
            for (int j=i; j<n; j+=k){   // make jumps, subarray k 
                if (j >= k - 1){
                    long long calc = pref[j + 1] - pref[j + 1 - k];
                    // standard Kadane transition
                    cur = max(calc, cur + calc);
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};