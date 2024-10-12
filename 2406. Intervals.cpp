class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // events, put on when to start or leave, process one at a time 
        // vector<pair<int, int>> events;
        // for (int i=0; i<n; i++){
            // events.push_back({intervals[i][0], intervals[i][1]});
        // }
        // sort
        // keep track of the gropus 
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> groups;

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> groups;

        // find groups 
        for (auto& i : intervals){
            int arrival = i[0], end = i[1];
            // use interval?
            if (!groups.empty() && groups.top() < arrival){
                int g = groups.top(); groups.pop();
            }
            groups.push(end);
        }
        return groups.size();
    }
};