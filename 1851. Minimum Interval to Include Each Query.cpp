class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        map<int, vector<int>> map;
        for (int i=0; i<queries.size(); i++){
            map[queries[i]].push_back(i);       // repeated vals
        }
        sort(intervals.begin(), intervals.end());
        vector<int> ans(queries.size(), -1);
        // pq for values on intervals 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    // size, last
        
        // get result for each query
        int i = 0;  // save i of intervals
        for (auto m : map){
            int query = m.first;

            // insert new values 
            while (i < intervals.size() && query >= intervals[i][0]){
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }

            // remove values 
            while (!pq.empty() && query > pq.top().second){
                pq.pop();
            }


            // update ans, get all the queries taht have same val
            if (pq.size()){
                for (auto& x : m.second){
                    ans[x] = pq.top().first;
                }
            }
        }
        
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
//         sort(intervals.begin(), intervals.end());
//         // save start in map 
//         map<int, int> map;
//         for (auto& interval : intervals){
//             int s = interval[0], e = interval[1];
//             // update 
//             if (map.find(s) != map.end()){
//                 map[s] = min(map[s], e);
//             }else{
//                 map[s] = e;
//             }
//         }
//         print(intervals);
//         // use bin search for each queries
//         vector<int> ans;
//         for (int& query : queries) {
//             int value = 0;
//             auto it = lower_bound(intervals.begin(), intervals.end(), query, 
//                 [](const vector<int>& interval, int query) {
//                     return interval[0] < query;
//                 });

//             if (it != intervals.end()) {
//                 cout << value << endl;
//                 value = (*it)[0];
//                 ans.push_back(map[value] - value + 1);
//             } else {
//                 ans.push_back(-1);
//             }
//         }

//         return ans;
//     }

//     void print(vector<vector<int>> intervals){
//         for (auto& interval : intervals){
//             cout << interval[0] << " " << interval[1] << endl;
//         }
//     }
// };