class Solution {
public:
    const int MOD = 1e9 + 7;

    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int countCoprime(vector<vector<int>>& mat) {
        map<int, int> count;
        count[0] = 1;
        // iterate all the rows 
        for (auto row : mat){
            map<int, int> nxt;
            // at each value on the col 
            for (auto val : row){
                // check the current GCD vals 
                for (auto p : count){
                    // get gcd and update next iteration for amount of values available 
                    int g = gcd(val, p.first);
                    nxt[g] = (p.second + nxt[g]) % MOD;
                }
            }
            count.swap(nxt);
        }
        return count[1];
    }
};

        // int n = mat.size(), m = mat[0].size();
        // // base case 
        // if (n == 1){
        //     int count = 0;
        //     for (int& x : mat[0]) if (x == 1) count++;
        //     return count;
        // }
        // // dp init 
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        // for (int j=0; j<m; j++) dp[0][j] = 1;
        // // dp count 
        // for (int i=1; i<n; i++){
        //     for (int j=0; j<m; j++){
        //         // check for every val upside if gcd is 1 
        //         for (int k=0; k<m; k++){
        //             if (gcd(mat[i][j], mat[i-1][k]) == 1){
        //                 dp[i][j] += dp[i-1][k];
        //             }
        //         }
        //     }
        // }

        // // output 
        // int ans = 0;
        // for (int j=0; j<m; j++) ans += dp[n-1][j];
        // return ans;

// class Solution {
// public:

//     const int sz = 151;
//     vector<vector<int>> pfac;
//     const int MOD = 1e9 + 7;

//     int gcd(int a, int b){
//         if (b == 0) return a;
//         return gcd(b, a % b);
//     }
    

//     Solution() : pfac(sz) {
//         // sieve erastothenes 
//         for (int i=2; i<sz; i++){
//             // if (!pfac.empty()) continue;   // if it has values 
//             if (!pfac.size()) continue;
//             for (int j=i; j<sz; j+=i){
//                 pfac[j].push_back(i);
//             }
//         }
//     }

//     long long dp(vector<vector<int>>& mat, map<set<int>, long long>& cache, int row, set<int>& primes){
//         // base case 
//         if (row == mat.size()){
//             return 1;
//         }
//         if (cache.find(primes) != cache.end()){
//             return cache[primes];
//         }
//         // children, iterate cols  
//         long long ans = 0;
//         for (int col=0; col<mat[0].size(); col++){
//             // check if it doesnt have same prime 
//             for ()
//             // add it to the prime set 
//             mat[row][col] == 1
//             if (){
//                 dp(mat, cache, row+1, primes);
//             }
//         }
//         return ans;
//     }    

//     int countCoprime(vector<vector<int>>& mat) {
//         // dp try all comb possible with caching 
//         // mat, cache(map<set, int>), row(int), primes(set)
        
//         map<set<int>, long long> cache;
//         set<int> primes;
//         return dp(mat, cache, row, primes);
//     }
// };

