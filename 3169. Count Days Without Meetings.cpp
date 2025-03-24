class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(), meetings.end());     // sort by starting day 
            // count the start pos 
            int count = meetings[0][0] - 1;
            int mx = meetings[0][1];
            for (int i=1; i<meetings.size(); i++){
                int start = meetings[i][0], end = meetings[i][1];
                if (mx < start){
                    count += (start - mx -1);
                }
                mx = max(mx, end);
            }
            // count end pos 
            if (mx != days){
                count += (days - mx);
            }
            return count; 
        }
    };