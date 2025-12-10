class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int const MOD = 1e9 + 7;
        // decrypt l < r 
        // must all greater than compelxity[0]
        for (int i=1; i<n; i++) if (complexity[0] >= complexity[i]) return 0;
        // calculate all the permutations -> math 
        // n ! 
        int ans = 1;
        for (int i=2; i<=n-1; i++){
            ans = (1LL * ans * i) % MOD;
        }
        return ans;
    }
};