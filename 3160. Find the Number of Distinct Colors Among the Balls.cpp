class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // vector<int> colour(limit+1, -1);   // x
        map<int, int> colour;
        map<int, int> freq;
        int cur_balls = 0;  
        vector<int> ans(queries.size()); 
        for (int i=0; i<queries.size(); i++){
            int idx = queries[i][0], col = queries[i][1];
            // reduce count if ball colour changes
            // if (colour[idx] != -1){
            if (colour.find(idx) != colour.end()){
                freq[colour[idx]]--;
                if (freq[colour[idx]] == 0){
                    cur_balls--;
                    freq.erase(colour[idx]);
                }
            }
            // add   
            if (freq[col] == 0 || freq.find(col) == freq.end()) cur_balls++;
            freq[col]++;
            colour[idx] = col;
            // output 
            ans[i] = cur_balls;
        }
        return ans;
    }
};