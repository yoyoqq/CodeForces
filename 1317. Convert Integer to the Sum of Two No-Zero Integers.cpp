class Solution {
public:
    bool noZero(string s){
        for (char c : s) if (c == '0') return false;
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i=n; i>=1; i--){
            int j = n-i;
            string x = to_string(i), y = to_string(j);
            if (noZero(x) && noZero(y)){
                return {i, j};
            }
        }
        return {-1, -1};
    }
};