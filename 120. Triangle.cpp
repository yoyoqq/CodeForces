class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=1; i<triangle.size(); i++){
            for (int j=0; j<triangle[i].size(); j++){
                if (j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if (j == triangle[i-1].size())
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
        int ans = 1e9;
        for (int& a : triangle[triangle.size()-1]){
            ans = min(ans, a);
        }
        return ans;
    }
};