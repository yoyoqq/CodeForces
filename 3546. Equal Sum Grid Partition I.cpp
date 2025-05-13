class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // 1. simulate the problem. use prefix for optimization 
        // 2. for the vertical, transpose the grid to reuse the prefix
        
        // transpose the matrix for same operation 
        // prefix on rows and cols 
        // separate row by row 

        vector<long> pre = prefix(grid);
        for (int i=0; i<pre.size(); i++){
            long left = pre[i];
            long right = pre.back() - pre[i];
            if (left == right) return true;
        }
        
        vector<vector<int>> rotated = transpose(grid);
        pre = prefix(rotated);
        for (int i=0; i<pre.size(); i++){
            long left = pre[i];
            long right = pre.back() - pre[i];
            if (left == right) return true;
        }
        
        return false;
    }

private:
    vector<long> prefix(vector<vector<int>>& matrix){
        int n = matrix.size(); 
        int m = matrix[0].size();
        vector<long> ans;
        for (int i=0; i<n; i++){
            long count = 0;
            for (int j=0; j<m; j++){
                count += matrix[i][j];
            }
            if (ans.empty())
                ans.push_back(count);
            else{
                ans.push_back(count + ans.back());
            }
        }
        return ans;
    }

    void print(vector<vector<int>>& rotated){
        for (int i=0; i<rotated.size(); i++){
            for (int j=0; j<rotated[0].size(); j++){
                cout << rotated[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> transpose(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows, 0));
        for (int j=0; j<cols; j++){
            for (int i=0; i<rows; i++){
                ans[j][i] = grid[i][j];
            }
        }
        return ans;
    }

};