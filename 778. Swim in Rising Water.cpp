class Solution {
public:
    vector<pair<int, int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mx = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // priority_queue<vector<int>> pq;
        pq.push({grid[0][0], 0, 0});    
        set<pair<int, int>> seen;
        // Dijkstra 
        while (pq.size()){
            auto tp = pq.top(); pq.pop(); 
            int val = tp[0], x = tp[1], y = tp[2];
            mx = max(mx, val);
            if (x == n-1 && y == m-1) return mx;
            for (auto [dx, dy] : directions){
                int nx = dx + x, ny = dy + y;
                if (0 <= nx && nx < n && 0 <= ny && ny < m && seen.find({nx, ny}) == seen.end()){
                    seen.insert({nx, ny});
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return mx;
    }
};



// class Solution {
// public:
//     vector<pair<int, int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};

//     bool possible(vector<vector<int>>& grid, int level){
//         int n = grid.size(), m = grid[0].size();
//         queue<pair<int, int>> q; q.push({0, 0});
//         set<pair<int, int>> seen; seen.insert({0, 0});
//         while (q.size()){
//             auto [x, y] = q.front(); q.pop();
//             // base case
//             if (x == n-1 && y == m-1) return true;
//             // children 
//             for (auto& [dx, dy] : directions){
//                 int nx = dx + x, ny = dy + y;
//                 if (0 <= nx && nx < n && 0 <= ny && ny < m && seen.find({nx, ny}) == seen.end() && grid[nx][ny] <= level){
//                     seen.insert({nx, ny});
//                     q.push({nx, ny});        
//                 }
//             }
//         }
//         return false;
//     }

//     int swimInWater(vector<vector<int>>& grid) {
//         int left = 0, right = 50*50, ans = 0;
//         while (left <= right){
//             int mid = left + (right - left)/2;
//             if (possible(grid, mid) && grid[0][0] <= mid){
//                 ans = mid;
//                 right = mid - 1;
//             }else{
//                 left = mid + 1;
//             }
//         }       
//         return ans;     
//     }
// };