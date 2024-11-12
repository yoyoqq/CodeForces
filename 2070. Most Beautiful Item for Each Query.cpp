class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // map the price to the beauty 
        map<int, int> m;
        m[0] = 0;
        vector<int> prices;
        prices.push_back(0);
        for (int i=0; i<items.size(); i++){
            // add into prices 
            if (m.find(items[i][0]) == m.end()) prices.push_back(items[i][0]);
            // include to map
            m[items[i][0]] = max(m[items[i][0]], items[i][1]);
        }
        sort(prices.begin(), prices.end());
        // for the map, in increasing order, update max if smaller is a max 
        int mx = 0;
        for (auto& [k, v] : m){
            m[k] = max(v, mx);
            mx = max(mx, v);
        }
        // for each query, binary search lower bound the price, 
        // use map to get the item bought and get beauty 
        // print(prices);
        // print(m);
        // cout << endl;
        vector<int> res;
        for (int& q : queries){
            // int q_price = *lower_bound(prices.begin(), prices.end(), q);
            // cout << q << " " << q_price << " " << m[q_price] << endl;
            auto it = lower_bound(prices.begin(), prices.end(), q);
            if (it != prices.begin() && (it == prices.end() || *it > q)){
                it--;
            }
            int q_price = *it;
            res.push_back(m[q_price]);
        }
        return res;
    }

private:
    void print(vector<int>& a){
        for (auto& x : a) cout << x << " ";
        cout << endl;
    }
    void print(map<int, int>& m){
        for (auto& [k, v] : m){
            cout << k << " " << v << endl;
        }
    }
};
