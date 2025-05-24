class Solution {
public:
    int minMoves(vector<string>& matrix) {
        // once we jump to teleportaion gate, 
        // jump to all -> we cannot go again to any 
        // add it to the stack 

        int n = matrix.size(), m = matrix[0].size();
        // find all the teleportation portals
        unordered_map<char, vector<pair<int, int>>> teleport;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if ('A' <= matrix[i][j] && matrix[i][j] <= 'Z'){
                    teleport[matrix[i][j]].push_back({i, j});
                }
            }
        }
        // find shortest path 
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; // moves, x, y
        // ! IF NOT USE TUPLE GIVES TLE
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // cannot use BFS due to teleport jumps, just use dijkstra 
        // queue<vector<int>> pq; // BFS works better, jump only if smaller 
        pq.push({0, 0, 0});
        vector<vector<int>> seen(n, vector<int>(m, 1e9));
        seen[0][0] = 0;
        vector<bool> use_teleport(26, true);
        while (pq.size()){
            // auto pqtop = pq.front(); pq.pop(); 
            auto [moves, x, y] = pq.top();
            pq.pop();
            if (x == n-1 && y == m-1) return moves;
            if (moves > seen[x][y]) continue;
            // use teleport 
            if ('A' <= matrix[x][y] && matrix[x][y] <= 'Z' && use_teleport[matrix[x][y]-'A']){
                char chr = matrix[x][y];
                use_teleport[chr-'A'] = false;
                for (auto v : teleport[chr]){
                    if (v.first == x && v.second == y) continue;
                    // only use if its smaller 
                    if (moves < seen[v.first][v.second]){
                        seen[v.first][v.second] = moves;
                        pq.push({moves, v.first, v.second});
                    }
                }
            }
            // move normally 
            for (auto [dx, dy] : directions){
                int nx = x + dx, ny = y + dy;
                // only use if its smaller, moves+1
                if (0 <= nx && nx < n && 0 <= ny && ny < m && moves+1 < seen[nx][ny] && matrix[nx][ny] != '#'){
                    seen[nx][ny] = moves+1;
                    pq.push({moves+1, nx, ny});
                }   
            }
        }
        return -1;
    }

private:
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
};