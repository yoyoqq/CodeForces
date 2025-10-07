class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        set<int> st;
        map<int, int> mp;
        for (int i=0; i<n; i++){
            if (rains[i] == 0){
                st.insert(i);
            }
            else{
                ans[i] = -1;
                int lake = rains[i];
                // there is another lake 
                if (mp.count(lake)){
                    auto idx = st.lower_bound(mp[rains[i]]);    // last pos of the idx leftmost full
                    if (idx == st.end()) return {};
                    ans[*idx] = lake;
                    st.erase(idx);
                }
                mp[lake] = i;
            }
        }
        return ans;
    }
};
