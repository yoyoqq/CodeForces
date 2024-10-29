class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // dp problem 
        // traverse the grid from cols to rows 
        // 
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> dp(m, vector<bool>(n));
        // first col is always 1
        for (int row=0; row<m; row++){
            dp[row][0] = true;
        }
        // dp 
        int last_col = 0;
        for (int col=0; col<n-1; col++){
            for (int row=0; row<m; row++){
                if (dp[row][col] == 0) continue;
                // mark up front down if <
                if (row-1 >= 0 && grid[row][col] < grid[row-1][col+1]){
                    dp[row-1][col+1] = true;
                    last_col = col + 1;
                }
                if (grid[row][col] < grid[row][col+1]){
                    dp[row][col+1] = true;
                    last_col = col + 1;
                }
                if (row + 1 < m && grid[row][col] < grid[row+1][col+1]){
                    dp[row+1][col+1] = true;
                    last_col = col + 1;
                }
            }
        }
        return last_col;
    }

private:
    void print(vector<vector<int>>& dp){
        int m = dp.size(), n = dp[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
};