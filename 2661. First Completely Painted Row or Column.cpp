class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // return when row/col painted, both == 0 
        vector<int> painted_row(m, n);
        vector<int> painted_col(n, m);
        // have coordinates of every arr[i]
        map<int, pair<int, int>> coordinates;
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                coordinates[mat[i][j]] = {i, j};
            }
        }
        // process each arr[i]
        for (int idx=0; idx<arr.size(); idx++){
            int num = arr[idx];
            // take out the i, j
            painted_row[coordinates[num].first]--;
            painted_col[coordinates[num].second]--;

            // cout << idx << " " << painted_col[coordinates[num][i].second] << " " << painted_row[coordinates[num][i].first] << endl;

            if (painted_row[coordinates[num].first] == 0 || painted_col[coordinates[num].second] == 0){
                return idx;
            }
        }
        return -1;
    }
};