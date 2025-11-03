class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto& g : guards) grid[g[0]][g[1]] = 1;
        for (auto& w : walls) grid[w[0]][w[1]] = 2;

        for (int i=0; i<m; i++){
            bool seen = false;
            // left to right 
            for (int j=0; j<n; j++){
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 3;
            }
            seen = false;
            // right to left 
            for (int j=n-1; j>=0; j--){
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 3;
            }
        }

        // column wise 
        for (int j=0; j<n; j++){
            // up down 
            bool seen = false;
            for (int i=0; i<m; i++){
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 3;
            }
            // bot up 
            seen = false;
            for (int i=m-1; i>=0; i--){
                if (grid[i][j] == 2) seen = false;
                else if (grid[i][j] == 1) seen = true;
                else if (seen) grid[i][j] = 3;
            }
        }
        int count = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j] == 0) count++;
            }
        }
        return count;


    }
};

// class Solution {
// public:

//     vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};

//     void dfs(int& m, int& n, vector<vector<int>>& grid, int x, int y, int& dx, int& dy){
//         if (0 > x || x == m || 0 > y || y == n || grid[x][y] == 1 || grid[x][y] == 2) return;
//         grid[x][y] = 3;
//         dfs(m, n, grid, x+dx, y+dy, dx, dy);
//     }

//     int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
//         vector<vector<int>> grid(m, vector<int>(n, 0));
//         // 0 -> empty cell 
//         // 1 -> wall 
//         // 2 -> guard 
//         // 3 -> in range to see 

//         // add walls 
//         for (auto wall : walls){
//             grid[wall[0]][wall[1]] = 1;
//         }
//         // BFS from every guard 
//         for (const auto guard : guards){
//             int tx = guard[0], ty = guard[1];
//             grid[guard[0]][guard[1]] = 2;
//             for (auto [dx, dy] : directions){
//                 // dfs(m, n, grid, guard[0]+dx, guard[1]+dy, dx, dy);
//                 int x = tx + dx, y = ty + dy;
//                 while (0 <= x && x < m && 0 <= y && y < n && grid[x][y] != 1 && grid[x][y] != 2){
//                     grid[x][y] = 3;
//                     x += dx, y += dy;
//                 }
                
//             }
//         }
//         // count empty cells 
//         int empty = 0;
//         for (int i=0; i<m; i++){
//             for (int j=0; j<n; j++){
//                 if (grid[i][j] == 0) empty++;
//                 // cout << grid[i][j] << " ";
//             }
//             // cout << endl;
//         }
//         return empty;
//     }
// };