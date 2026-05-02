class Solution {
public:
    // vector<int> rotate = {0, 1, 2, 5, 6, 8, 9};
    // ! rotate = 3 4 7 
    map<char, char> mp = {
        {'0', '0'},
        {'1', '1'},
        {'8', '8'},
        {'2', '5'},
        {'5', '2'},
        {'6', '9'},
        {'9', '6'}
    };

    bool valid(string& s) {
        string copy = "";
        for (char& c : s) {
            if (c == '3' || c == '4' || c == '7') return false;
            copy += mp[c];
        }
        return copy != s;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for (int i=1; i<=n; i++) {
            string s = to_string(i);
            if (valid(s)) ans++;
        }
        return ans;
    }
};


class Solution {
public:
    int dp[10][2][2];
    string s;

    bool isValid(int d) {
        return !(d == 3 || d == 4 || d == 7);
    }

    bool isChanged(int d) {
        // ignore 0 1 8 as does not change 
        return (d == 2 || d == 5 || d == 6 || d == 9);
    }

    int dfs(int pos, int tight, int hasChanged) {
        // base case 
        if (pos == s.size()) return hasChanged;
        // cache 
        if (dp[pos][tight][hasChanged] != -1) return dp[pos][tight][hasChanged];
        // children
        int limit = tight ? s[pos] - '0' : 9;   // bounded from top?
        int res = 0;

        for (int d=0; d<=limit; d++) {
            if (!isValid(d)) continue;
            int newTight = tight && (d == limit);
            int newChanged = hasChanged || isChanged(d);
            res += dfs(pos+1, newTight, newChanged);
        }
        return dp[pos][tight][hasChanged] = res;
    }

    int rotatedDigits(int n) {
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(0, 1, 0);
    }
};