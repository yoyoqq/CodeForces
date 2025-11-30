class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        // 1. calculate whole sum 
        int sm = 0;
        for (int& num : nums) sm = (sm + num) % p;
        // 2. whats our target? 
        int target = sm % p;
        if (target % p == 0) return 0;
        // 3. track the prev one prefix 
        map<int, int> mp;
        mp[0] = -1; 
        // 4. find the min 
        int ans = n;
        int cur = 0;
        for (int i=0; i<n; i++){
            cur = (cur + nums[i]) % p;
            // what do we need to remove ? 
            int needed = (cur - target + p) % p;
            // if we have seen it before we can remove it whats in between 
            if (mp.count(needed)){
                ans = min(ans, i - mp[needed]);    // 0 5 0 -> remove 5 0 
            }
            mp[cur] = i;
        }
        return (ans == n ? -1 : ans);
    }
};

// class Solution {
// public:
//     int minSubarray(vector<int>& nums, int p) {
//         // keep a map of modulos with its index. if happened again, means that we can remove to get it divisible by P 

//         // 1. if zero get index -> 6 0 5 7 
//         // 2. if repeated get size -> 3 4 2 4
//         // 3. if the (sm - x) % 0
//         long long sm = 0;
//         for (int& num : nums) sm = (sm + num) % p; 
//         int n = nums.size();
//         map<int, int> mp;
//         bool first_zero = true;
//         int ans = 1e9;
//         int cur = 0;
//         for (int i=0; i<n; i++){
//             cur = (cur + nums[i]) % p; 
//             cout << cur << endl;
//             // first case 
//             if (cur == 0){
//                 first_zero = false;
//                 ans = min(ans, n - 1 - i);
//             } 
//             // second case 
//             if (mp.count(cur)){
//                 ans = min(ans, i - mp[cur] - 1);
//             }
//             // third case 
//             if ((sm - nums[i]) % p == 0) ans = min(ans, 1);
//             mp[cur] = i; 
//         }
//         return (ans == 1e9 ? -1 : ans);
//     }
// };