class Solution {
public:
    int strangePrinter(string ss) {
        // get rid of duplicates next to each other 

        // dp
        // start index, end index 
        // two options 
        // naive: write one letter
        // look for next same letter and split removing one 

        // get rid of duplicates
        string cur; 
        cur += ss[0];
        for (int i=1; i<ss.size(); i++){
            if (cur.back() != ss[i]){
                cur += ss[i];
            }
        }
        cout << cur;
        // dp memo
        int n = cur.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return backtrack(dp, cur, 0, n-1);
    }

    int backtrack(vector<vector<int>>& memo, string& s, int i, int j){
        if (i > j){
            return 0;
        }
        if (memo[i][j] != 0){
            return memo[i][j];
        }
        // naive, take all slices
        int res = 1 + backtrack(memo, s, i+1, j);
        // slice if there is one in front that is tsame char split 
        for (int k=i+1; k<=j; k++){
            if (s[i] == s[k]){
                res = min(res, backtrack(memo, s, i+1, k) + backtrack(memo, s, k+1, j));
            }  // get rid of the letter, no need overcount as wilsl be counted again
            // eae -> ae     
        }
        memo[i][j] = res;
        return res;
    }
};