class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> res;
        int negative = 0;
        for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix.size(); j++){
                res.push_back(abs(matrix[i][j]));
                if (matrix[i][j] <= 0){
                    negative++;
                }
            }
        }
        negative = negative % 2;
        sort(res.begin(), res.end());
        // mark smallest ones as negative 
        for (int i=0; i<negative; i++){
            res[i] *= -1;
        }
        long long count = 0;
        for (int i=0; i<res.size(); i++){
            // cout << res[i] << " " ;
            count += res[i];
        }
        return count;
    }
};