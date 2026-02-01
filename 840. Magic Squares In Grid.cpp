class Solution {
public:

    bool check(vector<vector<int>>& grid, int i, int j){
        // check if 1 to 9;
        vector<int> nums(10, 0), row(3, 0), col(3, 0), diag1(3, 0), diag2(3, 0);
        for (int r=i; r<i+3; r++){
            for (int c=j; c<j+3; c++){
                if (grid[r][c] < 1 || grid[r][c] > 9) return false;
                row[r-i] += grid[r][c];
                col[c-j] += grid[r][c];
                nums[grid[r][c]]++;
                if (nums[grid[r][c]] > 1) return false;
                if (r-i == c-j) diag1[0] += grid[r][c];
                if ((r-i) + (c-j) == 2) diag2[0] += grid[r][c];
            }
        }
        
        for (int i=1; i<3; i++){
            if (row[i] != row[i-1] || col[i] != col[i-1]) return false;
        }
        for (int i=0; i<3; i++){
            if (diag1[0] != row[i] || diag2[0] != col[i]) return false;
        }
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        cout << n << " " << m << endl << endl;
        int ans = 0;
        for (int i=0; i<n-2; i++){
            for (int j=0; j<m-2; j++){
                // start at i,j
                ans += check(grid, i, j);
            }
        }
        return ans;
    }
};
