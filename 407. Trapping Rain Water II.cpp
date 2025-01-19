class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};

        int numOfRows = heightMap.size();
        int numOfCols = heightMap[0].size();

        vector<vector<bool>> visited(numOfRows, vector<bool>(numOfCols, false));
        priority_queue<Cell> boundary;

        // mark as seen and push to PQ, just the borders 
        for (int i=0; i<numOfRows; i++){
            boundary.push(Cell(heightMap[i][0], i, 0));
            boundary.push(Cell(heightMap[i][numOfCols-1], i, numOfCols-1));
            visited[i][0] = visited[i][numOfCols-1] = true;
        }
        for (int i=0; i<numOfCols; i++){
            boundary.push(Cell(heightMap[0][i], 0, i));
            boundary.push(Cell(heightMap[numOfRows-1][i], numOfRows-1, i));
            visited[0][i] = visited[numOfRows-1][i] = true;
        }

        int volume = 0;
        while (!boundary.empty()){
            Cell curCell = boundary.top(); boundary.pop();
            int curRow = curCell.row;
            int curCol = curCell.col;
            int minBoundaryHeight = curCell.height;

            // chlidren
            for (int dir=0; dir<4; dir++){
                int neighRow = curRow + dRow[dir];
                int neighCol = curCol + dCol[dir];
                if (isValidCell(neighRow, neighCol, numOfRows, numOfCols) && !visited[neighRow][neighCol]){
                    int neighHeight = heightMap[neighRow][neighCol];
                    // we can trap water 
                    if (neighHeight < minBoundaryHeight){
                        volume += minBoundaryHeight - neighHeight;
                    }
                    // update height
                    boundary.push(Cell(max(neighHeight, minBoundaryHeight), neighRow, neighCol));
                    visited[neighRow][neighCol] = true;
                }
            }
        }
        return volume;
    }


private:
    class Cell{
    public:
        int height, row, col;
        Cell(int height, int row, int col) :height(height), row(row), col(col){}
        bool operator<(const Cell& other) const{
            return height >= other.height;
        }
    };

    bool isValidCell(int row, int col, int numOfRows, int numOfCols){
        return row >=0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};



// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         // for each row and col
//         //      get pre/ suff 
//         // then, compute if possible 
//         //              get min() - height[x][y]
//         int n = heightMap.size();
//         int m = heightMap[0].size();
//         vector<vector<int>> row_pre(n, vector<int>(m, 0)), row_suff(n, vector<int>(m, 0)), col_pre(n, vector<int>(m, 0)), col_suff(n, vector<int>(m, 0));
//         // row_pre / row_suff
//         for (int row=0; row<n; row++){
//             for (int col=0; col<m; col++){
//                 if (col != 0){  // prefix 
//                     row_pre[row][col] = max(row_pre[row][col-1], heightMap[row][col-1]);
//                 }
//                 int col_inv = m - 1 - col;
//                 if (col_inv != m-1){
//                     row_suff[row][col_inv] = max(row_suff[row][col_inv+1], heightMap[row][col_inv+1]);
//                 }
//             }
//         }
//         // col_pre / col_suff
//         for (int col=0; col<m; col++){
//             for (int row=0; row<n; row++){
//                 if (row != 0){
//                     col_pre[row][col] = max(col_pre[row-1][col], heightMap[row-1][col]);
//                 }
//                 int row_inv = n - 1 - row;
//                 if (row_inv != n - 1){
//                     col_suff[row_inv][col] = max(col_suff[row_inv+1][col], heightMap[row_inv+1][col]);
//                 }
//             }
//         }
//         // print(col_pre);
//         // print(col_suff);
//         // output 
//         int volume = 0;
//         for (int row=1; row<n-1; row++){
//             for (int col=1; col<m-1; col++){
//                 int height = heightMap[row][col];
//                 if (row_pre[row][col] > height && row_suff[row][col] > height && col_pre[row][col] > height && col_suff[row][col] > height){
//                     int row_min = min(row_pre[row][col], row_suff[row][col]);
//                     int col_min = min(col_pre[row][col], col_suff[row][col]);
//                     volume += (min(row_min, col_min) - height);
//                 }
//             }
//         }
//         return volume; 
//     }

//     void print(vector<vector<int>>& arr){
//         int n = arr.size();
//         int m = arr[0].size();
//         for (int i=0; i<n; i++){
//             for (int j=0; j<m; j++){
//                 cout << arr[i][j] << " ";
//             }cout << endl;
//         }
//         cout << endl;
//     }
// };