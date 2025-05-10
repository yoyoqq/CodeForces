struct CompareFirst{
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[0] > b[0];
    }
};

class Solution {
public:
    vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        // dijkstra min path 
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<vector<int>, vector<vector<int>>, CompareFirst> pq; // time, x, y
        pq.push({0, 0, 0});
        set<pair<int, int>> seen;
        while (pq.size()){
            vector<int> top = pq.top(); 
            pq.pop();
            int time = top[0], x = top[1], y = top[2];
            // cout << time << " " << x << " " << y << endl;
            if (x == n-1 && y == m-1) return time;
            for (auto [dx, dy] : directions){
                int nx = dx + x, ny = dy + y;
                // cout << nx << " " << ny << endl;
                if (seen.find({nx, ny}) == seen.end() && (0 <= nx && nx < n && 0 <= ny && ny < m)){
                    seen.insert({nx, ny});
                    // evaluate the curtime, or if the next time is greater (moving to)
                    pq.push({max(time, moveTime[nx][ny]) + 1, nx, ny});
                }
            }
        }
        return -1; 
    }
};