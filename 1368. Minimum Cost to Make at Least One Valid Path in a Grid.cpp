class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        // optimize with bfs, shortest path algorithm 
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> queue;
        vector<vector<int>> matrix(n, vector<int>(m, INT_MAX));
        queue.push({0, 0, 0});
        while (queue.size()){
            auto cur = queue.top(); queue.pop();
            int cost = get<0>(cur), x = get<1>(cur), y = get<2>(cur);
            // cout << cost << " " << x << " " << y << endl;
            if (matrix[x][y] <= cost) continue;
            matrix[x][y] = cost;
            // children
            if (y+1 < m)    // col right
                queue.push({cost + ((grid[x][y] == 1) ? 0 : 1), x, y+1});
            if (y-1 >= 0) // col left 
                queue.push({cost + ((grid[x][y] == 2) ? 0 : 1), x, y-1});
            if (x+1 < n)
                queue.push({cost + ((grid[x][y] == 3) ? 0 : 1), x+1, y});
            if (x-1 >= 0)
                queue.push({cost + ((grid[x][y] == 4) ? 0 : 1), x-1, y});
        }
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<m; j++){
        //         cout << matrix[i][j] << " ";
        //     }cout << endl;
        // }
        return matrix[n-1][m-1];
    }
};

// USEOF DFS TOO MUCH MEMORY USED 
// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid) {
//         map<pair<int, int>, int> graph;
//         set<tuple<int, int, int>> seen;
//         return dp(grid, graph, seen, 0, 0, 0); // i j cost      
//     }

// private:
//     int dp(vector<vector<int>>& grid, map<pair<int, int>, int>& graph, set<tuple<int, int, int>>& seen, int x, int y, int cost){
//         if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return INT_MAX; 
//         if (x == grid.size() - 1 && y == grid[0].size() - 1) return cost; 

//         // seen
//         if (seen.find({x, y, cost}) != seen.end()) return INT_MAX;
//         seen.insert({x, y,  cost});
//         // children right left bottom up 
//         int cur_cost = INT_MAX;
//         cur_cost = min(cur_cost, dp(grid, graph, seen, x+1, y, cost + (grid[x][y] == 1 ? 0 : 1)));    // right
//         cur_cost = min(cur_cost, dp(grid, graph, seen, x-1, y, cost + (grid[x][y] == 2 ? 0 : 1)));    // left
//         cur_cost = min(cur_cost, dp(grid, graph, seen, x, y+1, cost + (grid[x][y] == 3 ? 0 : 1)));    // bottom
//         return cur_cost;
//     }
// };