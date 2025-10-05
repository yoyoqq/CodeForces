class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        
        for (int i=0; i<n; i++) dfs(i, 0, heights, pacific);
        for (int i=0; i<m; i++) dfs(0, i, heights, pacific);

        for (int i=0; i<n; i++) dfs(i, m-1, heights, atlantic);
        for (int i=0; i<m; i++) dfs(n-1, i, heights, atlantic);

        vector<vector<int>> ans;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (atlantic[i][j] & pacific[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited){
        visited[i][j] = true;
        for (auto& dir : directions){
            int x = dir[0] + i, y = dir[1] + j;
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (visited[x][y]) continue;
            if (heights[x][y] < heights[i][j]) continue;
            dfs(x, y, heights, visited);
        }
    }
    
};


// class Solution {
// private:
//     vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

//     bool bfs(vector<vector<int>>& heights, int i, int j){
//         int n = heights.size(), m = heights[0].size();
//         bool pacific = false, atlantic = false;
//         queue<pair<int, int>> q; q.push({i,j});
//         set<pair<int, int>> seen; seen.insert({i,j});
//         while (q.size()){
//             auto [x, y] = q.front(); q.pop();
//             // base case
//             if (x == 0 || y == 0) pacific = true;
//             if (x == n-1 || y == m-1) atlantic = true;
//             if (atlantic & pacific) return true;
//             // children  
//             for (auto& dir : directions){
//                 int nx = dir[0] + x, ny = dir[1] + y;
//                 // within matrix, smaller than current, not seen 
//                 if (0 <= nx && nx < n && 0 <= ny && ny < m && heights[nx][ny] <= heights[x][y] && seen.find({nx, ny}) == seen.end()){
//                     seen.insert({nx, ny});
//                     q.push({nx, ny});
//                 }
//             }
//         }
//         return (pacific & atlantic);
//     }
    
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int n = heights.size(), m = heights[0].size();
//         vector<vector<int>> ans;
//         for (int i=0; i<n; i++){
//             for (int j=0; j<m; j++){
//                 if (bfs(heights, i, j)){
//                     ans.push_back({i, j});
//                 }
//             }
//         }
//         return ans;
//     }
// };
