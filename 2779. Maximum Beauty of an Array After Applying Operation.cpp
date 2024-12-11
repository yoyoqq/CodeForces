class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // line sweep
        map<int, int> count;    // num : line sweep count
        for (int& n : nums){
            count[n-k]++;
            count[n+k+1]--;
        }
        int mx = 0;
        int sweep = 0;
        for (auto& [k, v] : count){
            cout << k << " " << v << endl;
            sweep += v;
            mx = max(mx, sweep);
        }
        return mx;
        
        // // from the range, so this is wrong!!!!!!
        // map<int, int> count;    // num : count
        // int mx = 0;
        // for (int& n : nums){
        //     // add 
        //     count[n]++;
        //     count[n-k]++;
        //     count[n+k]++;
        //     // update max
        //     mx = max(mx, max(count[n], max(count[n-k], count[n+k])));   
        // }
        // return mx;
    }
};