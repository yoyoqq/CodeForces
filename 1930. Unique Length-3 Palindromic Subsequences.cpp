class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // since its only length 3 
        // prefix, suffix of freq chars 
        // on each iteration for each char count as middle 

        // create suff 
        vector<int> suff(26, 0);
        for (int i=s.size()-1; i>=0; i--){
            int chr = s[i] - 'a';
            suff[chr]++;
        }
        // iterate for pref 
        vector<int> pref(26, 0);
        set<pair<int, int>> seen;
        for (int i=0; i<s.size(); i++){
            int mid = s[i] - 'a';
            // update 
            suff[mid]--;
            // count ? 
            for (int i=0; i<26; i++){
                if (suff[i] && pref[i] && seen.find({i, mid}) == seen.end()){
                    seen.insert({i, mid});
                }
            }
            pref[mid]++;
        }
        return seen.size();
    }
};