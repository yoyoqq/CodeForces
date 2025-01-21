#define ll long long 

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll firstRow = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        ll secondRow = 0;
        ll minSum = LONG_LONG_MAX;
        for (int i=0; i<grid[0].size(); i++){
            firstRow -= grid[0][i];
            minSum = min(minSum, max(firstRow, secondRow));
            secondRow += grid[1][i];
        }        
        return minSum;
    }
};



// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         // dijkstra? 
//         min_path(grid, 1);
//         // print(grid);
//         // long long cost = min_path(grid, 0);
//         print(grid);

//         int up = 0;
//         int down = 0;
//         for (int i=1; i<grid[0].size(); i++){
//             down = max(down + grid[1][i], down + grid[0][i]); // from down, from up
//             up += grid[0][i];   // keep taking up 
//         }
//         cout << up << " " << down;
//         return max(up, down);
//     }

// private:
//     long long min_path(vector<vector<int>>& grid, bool set_zero){
//         priority_queue<vector<long long>> pq;
//         pq.push({0, 0, 0});
//         while (pq.size()){
//             auto cur_node = pq.top(); pq.pop();
//             long long cur_cost = cur_node[0], x = cur_node[1], y = cur_node[2];
//             // base case
//             if (set_zero == 1){
//                 grid[x][y] = 0;
//             }
//             if (x == grid.size()-1 && y == grid[0].size()-1){
//                 return cur_cost;
//             } 
//             // children, go down, stay up 
//             if (x == 0){
//                 pq.push({cur_cost + grid[x+1][y], x+1, y});
//             }
//             if (y+1 < grid[0].size()){
//                 pq.push({cur_cost + grid[x][y+1], x, y+1});
//             }
//         }
//         return -1;
//     }

//     void print(vector<vector<int>>& grid){
//         for (int i=0; i<grid.size(); i++){
//             for (int j=0; j<grid[0].size(); j++){
//                 cout << grid[i][j] << " ";
//             }cout << endl;
//         }
//     }
// };



// // class Solution {
// // public:
// //     long long gridGame(vector<vector<int>>& grid) {
// //         // maximum num of points it can get 
// //         int sum = sum_grid(grid);
// //         int up = 0;
// //         int down = 0;
// //         for (int i=1; i<grid.size(); i++){
// //             down = max(down + grid[1][i], down + grid[0][i]); // from down, from up
// //             up += grid[0][i];   // keep taking up 
// //         }
// //         return sum - max(down, up) - grid[0][0] - grid[1][grid.size()-1];
// //     }

// // private:
// //     int sum_grid(vector<vector<int>>& grid){
// //         int n = grid.size(), m = grid[0].size();
// //         int sm = 0;
// //         for (int i=0; i<n; i++){
// //             for (int j=0; j<m; j++){
// //                 sm += grid[i][j];
// //             }
// //         }
// //         return sm;
// //     }
// // };