class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> pref(n, 0);
        vector<int> suff(n, 0);
        // decreasing 
        for (int i=1; i<n; i++){
            if (security[i-1] >= security[i])
                pref[i] = pref[i-1] + 1;
        }
        // increasing 
        for (int i=n-2; i>=0; i--){
            if (security[i] <= security[i+1])
                suff[i] = suff[i+1] + 1;
        }
        // print(pref);
        // print(suff);
        // check if time is correct
        // start from time, end n - time 
        vector<int> res;
        int end = (time == 0) ? n - time : n - time + 1;
        for (int i=time; i<end; i++){
            // cout << i << " ";
            // cout << pref[i] << " " << suff[i] << endl;
            if (pref[i] >= time && suff[i] >= time){
                res.push_back(i);
            }
        } 
        return res;
    }

private:
    void print(vector<int>& a){
        for (auto& x : a) cout << x << " ";
        cout << endl;
    }
};