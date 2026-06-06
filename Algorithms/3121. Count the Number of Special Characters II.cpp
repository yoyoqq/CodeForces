class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, int> mp;
        for (int i=0; i<word.size(); i++) {
            // lower 
            if ('a' <= word[i] && word[i] <= 'z') {
                mp[word[i]] = i;
            } 
            // upper 
            else if (mp.count(word[i]) == 0) {
                mp[word[i]] = i;
            }
        }
        int count = 0;
        for (char i='a'; i<='z'; i++) {
            char caps = 'A' - ('a' - i);
            // cout << i << " " << caps << endl;
            if (mp.count(i) && mp.count(caps) && mp[i] < mp[caps]) count++;
        }
        return count;
    }
};