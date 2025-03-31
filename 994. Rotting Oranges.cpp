class Solution {
    public:
    
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            queue<pair<int, int>> rotten;
            int fresh = 0;
            for (int i=0; i<m; i++){
                for (int j=0; j<n; j++){
                    if (grid[i][j] == 2){
                        rotten.push({i, j});
                    } 
                    if (grid[i][j] == 1) fresh++;
                }
            }
            
            if (fresh == 0) return 0;
            int minutes = 0;
            // bfs till all have been iterated 
            while (rotten.size()){
                int sz = rotten.size();
                for (int i=0; i<sz; i++){   // iterate one level
                    auto [x, y] = rotten.front(); rotten.pop();
                    for (auto [dx, dy] : directions){
                        int nx = dx + x, ny = dy + y;
                        if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] == 1){
                            grid[nx][ny] = 2;
                            fresh--;
                            rotten.push({nx, ny});
                        }
                    }
                }
                minutes++;
            }
            return (fresh == 0 ? minutes-1 : -1);
        }
    };