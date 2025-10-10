class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        // dp for each one the earliest time 
        int n = skill.size();
        vector<long long> times(n, 0);
        // for every mana 
        for (int j=0; j<mana.size(); j++){
            // get the amount of time to iterate the whole arr 
            long long cur_time = 0;
            for (int i=0; i<n; i++){
                cur_time = max(cur_time, times[i]) + 1LL * skill[i] * mana[j];
            }
            times[n-1] = cur_time; 
            // update times backwards 
            for (int i=n-2; i>=0; i--){
                times[i] = times[i+1] - skill[i+1] * mana[j];
            }
        }
        return times.back();
    }
};