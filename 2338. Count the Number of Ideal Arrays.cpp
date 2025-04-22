// COMBINATORICS 
int comb[10001][14] = { 1 }, cnt[10001][14] = {}, mod = 1000000007;
class Solution {
public: 
int idealArrays(int n, int maxValue) {
    if (comb[1][1] == 0) { // one-time computation.
        for (int s = 1; s <= 10000; ++s) // nCr (comb)
            for (int r = 0; r < 14; ++r)
                comb[s][r] = r == 0 ? 1 : (comb[s - 1][r - 1] + comb[s - 1][r]) % mod;
        for (int div = 1; div <= 10000; ++div) { // Sieve of Eratosthenes
            ++cnt[div][0];
            for (int i = 2 * div; i <= 10000; i += div)
                for (int bars = 0; cnt[div][bars]; ++bars)
                    cnt[i][bars + 1] += cnt[div][bars];
        }
    }
    int res = 0;
    for (int i = 1; i <= maxValue; ++i)
        for (int bars = 0; bars < min(14, n) && cnt[i][bars]; ++bars)
            res = (1LL * cnt[i][bars] * comb[n - 1][bars] + res) % mod;
    return res;
}
};

// ? SIEVE ERASTOTHENES
// int dp[10000] = {}, mod = 1000000007;
// class Solution {
// public:
//     int idealArrays(int n, int maxValue) {
//         fill(begin(dp), begin(dp) + maxValue, 1);
//         for (int i = 1; i < n; ++i)
//             for (int j = 1; j <= maxValue / 2; ++j) {
//                 for (int k = 2 * j; k <= maxValue / 2; k += j)
//                     dp[j - 1] = (dp[j - 1] + dp[k - 1]) % mod;
//                 dp[j - 1] = (dp[j - 1] + maxValue / j - maxValue / 2 / j) % mod;
//             }
//         return accumulate(begin(dp), begin(dp) + maxValue, 0, [&](int s, int n){ return (s + n) % mod; });
//     }
// };


// ? BRUTEFORCE DP
// class Solution {
// public:
//     int idealArrays(int n, int maxValue) {
//         int dp[10000] = {}, mod = 1000000007;
//         fill(begin(dp), begin(dp) + maxValue, 1);
//         // fill the dp table 
//         for (int i=1; i<n; i++){
//             // for all the nums 1 to maxValue
//             for (int j=1; j<=maxValue/2; j++){
//                 // its multiples
//                 for (int k=2*j; k<=maxValue/2; k+=j){
//                     dp[j-1] = (dp[j-1] + dp[k-1]) % mod;    // sum prev comb 
//                 }
//                 dp[j-1] = (dp[j-1] + maxValue / j - maxValue/2/j) % mod;    // add 
//             }
//         }
//         return accumulate(begin(dp), begin(dp) + maxValue, 0, [&](int s, int n){ return (s+n) % mod;});
//     }
// };


// class Solution {
//     public:
//         int n;
//         int maxValue;
//         int MOD = 1e9 + 7;

//         int idealArrays(int n, int maxValue) {
//             // 1 <= arr[i] <= maxValue
//             // arr[i] % arr[i-1]
//             this->n = n;
//             this->maxValue = maxValue;
//             long long ans = 0;
//             // choose any starting value from 1…maxValue
//             for (int first = 1; first <= maxValue; ++first) {
//                 ans = (ans + dp(1, first)) % MOD;
//             }
//             return int(ans);
//         }
    
//     private:
//         map<pair<int, int>, int> cache;

//         int dp(int idx, int last){
//             if (idx >= n){
//                 return 1;
//             }
//             if (cache.find({idx, last}) != cache.end()) return cache[{idx, last}];
//             // cout << idx << " " << last << endl;
//             long long count = 0;
//             for (int i=1; i<=maxValue; i++){
//                 if (i % last == 0){
//                     count = (count + dp(idx+1, i)) % MOD;
//                 }   
//             }
//             cache[{idx, last}] = count;
//             return (int)count;
//         }
//     };

// // int main(){
// //     Solution sol;
// //     cout << sol.idealArrays(2, 5) << endl;
// //     return 0;
// // }