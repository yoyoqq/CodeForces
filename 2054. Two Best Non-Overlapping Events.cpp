class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // min queue 
        int maxSum = 0;
        int curSum = 0;
        sort(events.begin(), events.end());
        // for (int i=0; i<events.size(); i++){
        for (auto& event : events){
            // check if there is non overlapping event
            while (!pq.empty() && pq.top().first < event[0]){
                curSum = max(curSum, pq.top().second);
                pq.pop();
            }
            // calculate new 
            maxSum = max(maxSum, curSum + event[2]);
            pq.push({event[1], event[2]});
        }
        return maxSum;
    }
};