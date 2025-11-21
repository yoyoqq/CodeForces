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


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, int> left, right;
        int n = s.size();
        for (int i=0; i<n; i++){
            if (left.find(s[i]) == left.end()) left[s[i]] = i;
            right[s[i]] = i;
        }
        int ans = 0;
        // check for all from a-z 
        for (char c='a'; c<='z'; c++){
            // must have +3 size 
            if (left[c] >= right[c]) continue;
            vector<bool> seen(26, false);
            for (int i=left[c]+1; i<right[c]; i++){
                seen[s[i]-'a'] = true;
            }
            ans += count(seen.begin(), seen.end(), true);
        }
        return ans;
    }
};