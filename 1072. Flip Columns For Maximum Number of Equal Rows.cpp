class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        unordered_map<string, int> map;
        for (int i=0; i<N; i++){
            string cur = "";
            for (int j=1; j<M; j++){
                if (matrix[i][j-1] != matrix[i][j])
                    cur += "1";
                else 
                    cur += "0";
            }
            map[cur]++;
        }
        // get max 
        int mx = 0;
        for (auto& [k, v] : map){
            mx = max(mx, v);
        }
        return mx;
    }
};