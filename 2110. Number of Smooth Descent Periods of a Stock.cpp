#define ll long long 

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 1;
        int count = 1;
        for (int i=1; i<prices.size(); i++){
            // descending 
            if (prices[i-1] - 1 == prices[i]){
                count++;
            }
            else{
                count = 1;
            }
            ans += count;
        }
        return ans;
    }
};
