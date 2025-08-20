class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        int res = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j] == 1){
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else {
                        dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int countSquares(vector<vector<int>>& matrix) {
//         // prefix sum of row and col 
//         // 1, 2, 3 in both prefixes 
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> prow(n, vector<int>(m));
//         vector<vector<int>> pcol(n, vector<int>(m));
//         for (int i=0; i<n; i++){
//             for (int j=0; j<m; j++){
//                 if (i == 0){
//                     prow[i][j] = matrix[i][j];
//                 }else{
//                     prow[i][j] += prow[i-1][j] + matrix[i][j];
//                 }
//             }
//         }
//         for (int j=0; j<m; j++){
//             for (int i=0; i<n; i++){
//                 if (j == 0){
//                     pcol[i][j] = matrix[i][j];
//                 }else{
//                     pcol[i][j] += pcol[i][j-1] + matrix[i][j]; 
//                 }
//             }
//         }
//         int count = 0;
//         for (int i=0; i<n; i++){
//             for (int j=0; j<m; j++){
//                 int x = i, y = j, current = 1;
//                 while (x < n && y < m && matrix[x][y] == 1 && prow[x][y] >= current && pcol[x][y] >= current && prow[i][y] >= current && pcol[x][j] >= current){
//                     x++, y++, count++, current++;
//                 }
//             }
//         }
//         return count;
//     }
// };
//         // for (int i=0; i<n; i++){
//         //     for (int j=0; j<m; j++){
//         //         if (matrix[i][j] != 0) continue;
//         //         int x = i;
//         //         int y = j;
//         //         // 1 
//         //         while (matrix[x][y] == 1 && 
//         //             // prow[x] - prow[i] == x-i
//         //         ){
//         //             count++;
//         //             x++;
//         //             y++;
//         //         }
//         //     }
//         // }
