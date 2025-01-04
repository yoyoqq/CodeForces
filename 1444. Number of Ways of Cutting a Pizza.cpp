class Solution {
public:
    int const MOD = 1e9 + 7;

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(k, vector(m, vector(n, -1)));    // k row col 
        vector<vector<int>> pref(m+1, vector(n+1, 0));
        for (int r=m-1; r>=0; r--)
            for (int c=n-1; c>=0; c--)
                pref[r][c] = pref[r][c+1] + pref[r+1][c] - pref[r+1][c+1] + (pizza[r][c] == 'A');
        
        return dfs(m, n, k-1, 0, 0, dp, pref);
    }

    int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<int>>& pref){
        if (pref[r][c] == 0) return 0;
        if (k == 0) return 1;
        if (dp[k][r][c] != -1) return dp[k][r][c];
        int ans = 0;
        // horizontal cuts 
        for (int nr=r+1; nr<m; nr++)
            if (pref[r][c] - pref[nr][c] > 0)
                ans = (ans + dfs(m, n, k-1, nr, c, dp, pref)) % MOD;
        // vertical cuts 
        for (int nc=c+1; nc<n; nc++)
            if (pref[r][c] - pref[r][nc] > 0)
                ans = (ans + dfs(m, n, k-1, r, nc, dp, pref)) % MOD;
        return dp[k][r][c] = ans;
    }
};




// class Solution {
// public:
//     int const MOD = 1e9 + 7;

//     int ways(vector<string>& pizza, int k) {
//         // how to cut pizza -> take or no take 
//         // how to know pieces left ? -> brute force
//         // int apples = count_apples(pizza, 0, 0, pizza.size(), pizza[0].size());
//         k--;
//         map<tuple<int, int, int>, int> memo;
//         return dp(pizza, memo, k, 0, 0);
//     }

//     int dp(vector<string>& pizza, map<tuple<int, int, int>, int>& memo, int k, int i, int j){
//         // base case 
//         if (k == 0){
//             // are there apples remaining ? 
//             int apples_remaining = count_apples(pizza, i, j);
//             if (apples_remaining) return 1;
//             return 0;
//         } 
//         if (i==pizza.size() || j == pizza[0].size()) return 0;
//         if (memo.find({k, i, j}) != memo.end()) return memo[{k, i, j}];
//         // children, skip, take col, take row 
//         int slices = 0;
//         // take row only if there are apples in the row 
//         slices = (slices + dp(pizza, memo, k, i+1, j)) % MOD;   // skip row
//         slices = (slices + dp(pizza, memo, k, i, j+1)) % MOD;   // skip col
//         int row_apples = count_row(pizza, i, j);
//         if (row_apples) slices = (slices + dp(pizza, memo, k-1, i+1, j)) % MOD;   // take row
//         int col_apples = count_col(pizza, i, j);
//         if (col_apples) slices = (slices + dp(pizza, memo, k-1, i, j+1)) % MOD;   // take col

//         memo[{k, i, j}] = slices;
//         return slices;
//     }

//     int count_row(vector<string>& pizza, int i, int j){
//         if (i >= pizza.size()) return 0;
//         int apples = 0;
//         for (int col = j; col < pizza[0].size(); col++) {
//             if (pizza[i][col] == 'A') apples++;
//         }
//         return apples;
//     }

//     int count_col(vector<string>& pizza, int i, int j){
//         if (j >= pizza[0].size()) return 0;
//         int apples = 0;
//         for (int row = i; row < pizza.size(); row++) {
//             if (pizza[row][j] == 'A') apples++;
//         }
//         return apples;
//     }

//     int count_apples(vector<string>& pizza, int i, int j){
//         int apples = 0;
//         for (int row=i; row<pizza.size(); row++){
//             for (int col=j; col<pizza[0].size(); col++){
//                 if (pizza[row][col] == 'A') apples++;
//             }
//         }
//         return apples;
//     }
// };