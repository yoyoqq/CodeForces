class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // create graph 
        // create connections 
        map<int, map<int, int>> graph;
        map<int, vector<int>> connections;
        for (auto& road : roads) {
            int x = road[0], y = road[1], dist = road[2];
            graph[x][y] = dist;
            graph[y][x] = dist;
            connections[x].push_back(y);
            connections[y].push_back(x);
        }
        // bfs 
        int ans = INT_MAX;
        set<int> seen;
        vector<int> dfs = {1};
        while (dfs.size()) {
            // base case 
            int cur = dfs.back();
            dfs.pop_back();
            if (seen.find(cur) != seen.end()) continue; 
            seen.insert(cur);
            // children
            for (auto& connection : connections[cur]) {
                dfs.push_back(connection);
                ans = min(ans, graph[cur][connection]);
            }
        }
        return ans;
    }
};