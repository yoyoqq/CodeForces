class Solution {
public:

    int const MOD = 1e9 + 7;

    int get_val(char x) {
        // board[i][j]
        if (x == 'E' || x == 'S') return 0;
        else return x - '0';
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        // e23
        // 2x2
        // 12s

        // 1. maximum count 
        // dp,  max(left, upleft, up)
        // 2. all the paths to use (dp)
        // count max val, paths
        // (count, paths)
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {-1, -1}};
        int n = board.size(), m = board[0].size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int, int>>(m, {0, 0}));
        dp[0][0] = {0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // check directions 
                // dp[i][j] = max({dp[i][j], left, up, leftup});
                for (auto dir : directions) {
                    int x = i + dir.first, y = j + dir.second;
                    // out of grid
                    if (0 > x || x >= n || 0 > y || y >= m) continue;
                    // invalid op
                    if (board[i][j] == 'X' || (dp[x][y].first == 0 && dp[x][y].second == 0)) continue;
                    int cur_count = dp[x][y].first + get_val(board[i][j]);
                    int cur_paths = dp[x][y].second;
                    // change? 
                    // 1. greater val 
                    if (dp[i][j].first < cur_count) {
                        dp[i][j].first = cur_count;
                        dp[i][j].second = cur_paths;
                    }
                    // 2. equals val 
                    else if (dp[i][j].first == cur_count) {
                        dp[i][j].second = (dp[i][j].second + cur_paths) % MOD;
                    }
                }
            }
        }
        for (int i=0; i<n; i++){ 
            for (int j=0; j<m; j++){
                cout << dp[i][j].first << " " << dp[i][j].second << " | ";
            }
            cout << endl;
        }
        return {dp[n-1][m-1].first, dp[n-1][m-1].second};
    }
};