class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        // time, row, col 
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        while (pq.size()){
            auto cur = pq.top(); 
            pq.pop();
            int time = cur[0], row = cur[1], col = cur[2];
            if (row == rows-1 && col == cols -1) return time;
            if (visited[row][col] == true) continue;
            visited[row][col] = true;
            for (auto& d : directions){
                int nextRow = row + d[0], nextCol = col + d[1];
                if (!(nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols)) continue;
                int increment = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + increment, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        return -1;
    }
};