// 2373. Largest Local Values in a Matrix
// max pooling 

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> matrix(n-2, vector<int>(n-2));
        for (int row=1; row<n-1; row++){
            for (int col=1; col<n-1; col++){
                // check all dir 
                matrix[row-1][col-1] = find_largest(grid, row, col); 
            }
        }
        return matrix;
    }

private:
    int find_largest(vector<vector<int>>& grid, int& row, int& col){
        int mx = 0;
        for (int i=row-1; i<row+2; i++){
            for (int j=col-1; j<col+2; j++){
                mx = max(mx, grid[i][j]);
            }
        }
        return mx;
    }
};