class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            // starting at top left 
            // amount from its row and col 
            // 1 3 1 
            // 1 3 1 
            // 2 2 
            // 2 2 
            // 
            // 
            // max(0, min(row,col)-2);
            vector<int> rows_first(n, 1e9);
            vector<int> rows_last(n, -1);
            vector<int> cols_first(n, 1e9);
            vector<int> cols_last(n, -1);
            for (int i = 0; i < buildings.size(); i++) {
                int row = buildings[i][0] - 1, col = buildings[i][1] - 1;
                // rows by col 
                // cols by row 
                // get min and max bound 
                rows_first[row] = min(rows_first[row], col);    
                rows_last[row] = max(rows_last[row], col);
                cols_first[col] = min(cols_first[col], row);
                cols_last[col] = max(cols_last[col], row);
            }
            
            int count = 0;
            for (auto building : buildings){
                int row = building[0]-1, col = building[1]-1;
                if (rows_first[row] == 1e9) continue;
                if (cols_first[col] == 1e9) continue; // if we dont have any value on it skip
                // its in between 
                if (rows_first[row] < col && col < rows_last[row] && cols_first[col] < row && row < cols_last[col]){
                    count++;
                }
            }
            return count;
        }
    };
            // for (int& x : rows) cout << x << " "; cout << endl;
            // for (int& x : cols) cout << x << " "; cout << endl;
    
            // int count = 0;
            // for (int i=0; i<n; i++){
            //     for (int j=0; j<n; j++){
            //         if (rows[i] > 2 && cols[j] > 2) count++;
            //         // count += max(0, min(rows[i], cols[j])-2);
            //         // if (rows[i] > 2 && cols[j] > 2){
            //         // }
            //     }
            // }
            // return count;