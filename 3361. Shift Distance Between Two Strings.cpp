class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long res = 0;
        int n = s.size();
        for (int i=0; i<n; i++){
            res += min(calc(s[i], t[i], nextCost, 1),
                calc(s[i], t[i], previousCost, -1));
        }
        return res;
    }

long calc(char c1, char c2, vector<int>& cost, int inc){
    long res = 0;
    while (c1 != c2){
        res += cost[c1-'a'];
        c1 = 'a' + (c1 - 'a' + inc + 26) % 26;
    }
    return res;
}
};