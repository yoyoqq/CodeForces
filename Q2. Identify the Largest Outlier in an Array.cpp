class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int, int> m;
        int sm = 0;
        for (int& n : nums){
            m[n]++;
            sm += n;
        }
        // sum(all) - (sm*2) = out
        int outlier = INT_MIN;
        // for (int& n : nums){
        for (auto [n, v] : m){
            int calc = sm - (n * 2);
            // if calc == n it has to be greather than 1
            // otherwise if diff, needs to be in map
            if (m.find(calc) != m.end() && calc != n){
                outlier = max(outlier, calc);
                // if (abs(calc) > abs(outlier))
                //     outlier = calc;
            }
            if (calc == n && m[calc] >= 2){
                outlier = max(outlier, calc);
            }
            // cout << n << " " << v << " "<< calc << endl;
        }
        
        return outlier;
    }
};