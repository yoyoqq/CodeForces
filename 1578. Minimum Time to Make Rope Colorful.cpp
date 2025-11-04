class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // sliding window, two pointers 
        int n = colors.size();
        int ans = 0;
        int i = 0, sum = 0, mx = 0;
        for (int j=0; j<n; j++){
            // cout << i << " " << j << " " << ans << endl;
            // still the same 
            if (colors[i] == colors[j]){
                sum += neededTime[j];
                mx = max(mx, neededTime[j]);
            }
            // different 
            else{
                ans += sum - mx;
                sum = neededTime[j], mx = neededTime[j];
                i = j;
            }
        }
        ans += sum - mx;
        return ans;
    }
};