class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int count = 0;
        for (int i=0; i<matrix.size(); i++)
            for (int j=0; j<matrix[0].size(); j++){
                set<pair<int, int>> seen;
                seen.insert({i, j});
                count = max(count, dp(matrix, seen, i, j, matrix[i][j]));
                seen.erase({i, j});
            }
        return count;
    }

    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    map<vector<int>, int> cache;

    int dp(vector<vector<int>>& matrix, set<pair<int, int>>& seen, int i, int j, int cur){
        // base case
        if (cache.find({i, j, cur}) != cache.end()) return cache[{i, j, cur}];
        // children
        int count = 1;
        for (auto& next_dir : dir){
            int x = next_dir[0] + i;
            int y = next_dir[1] + j;
            if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && seen.find({x, y}) == seen.end() && cur < matrix[x][y]) {
                seen.insert({x, y});
                count = max(count, 1 + dp(matrix, seen, x, y, matrix[x][y]));
                seen.erase({x, y});
            }
        } 
        cache[{i, j, cur}] = count;
        return count;
    }
};