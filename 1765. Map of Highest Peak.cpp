class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // gather all the water and spread with bfs 
        queue<pair<int, int>> queue;
        for (int i=0; i<isWater.size(); i++){
            for (int j=0; j<isWater[0].size(); j++){
                if (isWater[i][j] == 1)
                    queue.push({i, j});
            }
        }
        // mark highest peak 
        vector<vector<int>> height(isWater.size(), vector<int>(isWater[0].size(), 0));
        while (queue.size()){
            // for all of them expand to the next one 
            auto cur_node = queue.front(); queue.pop();
            // children
            for (vector<int> dir : directions){
                int dx = dir[0] + cur_node.first;
                int dy = dir[1] + cur_node.second;
                // inside the grid and not marked 
                if (0 <= dx && 0 <= dy && dx < isWater.size() && dy < isWater[0].size() && height[dx][dy] == 0 && isWater[dx][dy] == 0){
                    height[dx][dy] = height[cur_node.first][cur_node.second] + 1; 
                    queue.push({dx, dy});
                }
            }
        }

        return height;
    }
};