class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<int> a(n*n+1);
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    a[grid[i][j]]++;
                }
            }
            vector<int> ans = {-1, -1};
            for (int i=0; i<a.size(); i++){
                if (a[i] == 2) ans[0] = i;
                if (a[i] == 0) ans[1] = i;
            }
            return ans;
        }
    };