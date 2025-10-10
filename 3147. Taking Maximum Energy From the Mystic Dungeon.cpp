class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // greedy 
        int n = energy.size();
        int ans = INT_MIN;
        // i groups 
        for (int i=0; i<k; i++){
            // iterate j group 
            int cur = 0;
            for (int j=i; j<n; j+=k){
                cur = max(energy[j], energy[j]+cur);
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};