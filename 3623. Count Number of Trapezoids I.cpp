#define ll long long

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        ll ans = 0, sm = 0;
        const int MOD = 1e9 + 7;
        // 1. 
        map<int, int> freq;
        for(auto& p : points) freq[p[1]]++; // of the level Y count the freq 
        // 2.
        for (auto& [k, v] : freq){
            ll edges = 1LL*v * (v - 1) / 2; // number of ways to choose 2 with X 
            ans += edges * sm;
            sm += edges;
        }
        return ans % MOD;
    }
};
