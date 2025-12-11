class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // x horizontal , y vertical  
        // min max 
        vector<pair<int, int>> hor, ver;
        for (int i=0; i<=n; i++){
            hor.push_back({INT_MAX, INT_MIN});
            ver.push_back({INT_MAX, INT_MIN});
        }
        // update x and y 
        for (auto build : buildings){
            int x = build[0], y = build[1];
            // x -> vertical 
            ver[x].first = min(ver[x].first, y);
            ver[x].second = max(ver[x].second, y);
            // y -> horizontal 
            hor[y].first = min(hor[y].first, x);
            hor[y].second = max(hor[y].second, x);
        }
        // for (auto [f, s] : ver){
        //     cout << f << " " << s << endl;
        // }
        // count 
        int ans = 0;
        for (auto build : buildings){
            int x = build[0], y = build[1];
            if (hor[y].first != INT_MAX && ver[x].first != INT_MAX){
                // if its in between                
                // cout << x << " " << y << endl;
                // cout << (hor[y].first < x) << " " << (x < hor[y].second) << " " << (ver[x].first < y) << " " << (ver[x].second > y) << endl << endl;
                if (hor[y].first < x && x < hor[y].second && ver[x].first < y && ver[x].second > y){
                    ans++;
                }
            }
        }
        return ans;
    }
};