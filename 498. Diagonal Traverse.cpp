class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int i=0, j=0; 
        vector<int> ans;
        bool up = true;
        // num of lines iterate 
        while (ans.size() < n * m){
            ans.push_back(mat[i][j]);
            if (up){
                // go up right, there are 2 types of walls 
                if (j == m-1){  // hit the right wall 
                    i++; up = false;
                }
                else if (i == 0){
                    j++; up = false;
                }else{
                    i--; j++;
                }
            }
            else{
                // downwards 2 walls 
                if (i == n-1){
                    j++; up = true;
                }
                else if (j == 0){
                    i++; up = true;
                }
                else{
                    i++; j--;
                }
            }
        }
        return ans;
    }
};