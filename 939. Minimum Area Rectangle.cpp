class Solution {
    public:
        int minAreaRect(vector<vector<int>>& points) {
            int n = points.size();
            set<pair<int, int>> seen;
            int ans = 1e9;
            for (int i=0; i<n; i++){
                seen.insert({points[i][0], points[i][1]});
            }
            // min area that can be used for a rectangle -> w * l 
            for (int i=0; i<n; i++){
                int sx = points[i][0], sy = points[i][1];
                for (int j=i+1; j<n; j++){
                    int ex = points[j][0], ey = points[j][1];
                    // check if sides exist 
                    if (ex != sx && sy != ey && seen.find({ex, sy}) != seen.end() && seen.find({sx, ey}) != seen.end()){
                        ans = min(ans, abs(ex-sx) * abs(sy-ey));
                    }
                }
            }
            return ans != 1e9 ? ans : 0;
        }
    };