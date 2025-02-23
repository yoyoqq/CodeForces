class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            vector<int> mx; 
            for (int i=0; i<grid.size(); i++){
                vector<int> cur_row = grid[i];
                sort(cur_row.rbegin(), cur_row.rend());
                for (int j=0; j<limits[i]; j++){
                    mx.push_back(cur_row[j]);
                }
            }
            // take max 
            sort(mx.rbegin(), mx.rend());
            long long count = 0;
            int i = 0;
            while (k--){
                count += mx[i];
                i++;
            }
            return count;
        }
    };