struct Compare{
    bool operator()(vector<int>& a, vector<int>& b){
        return a[0] > b[0];
    }
};

struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // dijsktra algoirhtm shortest path 
        // if obstacle ++
        // 0 -> empty
        // 1 -> obstacle
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        unordered_set<pair<int, int>, PairHash> seen; 
        vector<vector<int>> directions = {{0,1}, {1,0}, {-1, 0}, {0, -1}};

        pq.push({0, 0, 0});     // cost, x, y
        seen.insert({0, 0});
        while (pq.size()){
            vector<int> p = pq.top(); pq.pop();
            int cost = p[0], x = p[1], y = p[2];
            // base case 
            if (x == grid.size()-1 && y == grid[0].size()-1){
                return cost;
            }
            // children
            for (vector<int>& dir : directions){
                int xx = x + dir[0], yy = y + dir[1];
                // out cases, if found  ||  out of grid
                if (seen.find({xx, yy}) != seen.end()) continue;
                if (!(xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size())) continue;
                seen.insert({xx, yy});
                if (grid[xx][yy] == 1){
                    pq.push({cost+1, xx, yy});
                }else{
                    pq.push({cost, xx, yy});
                }
            }
        }
        return -1;
    }
};