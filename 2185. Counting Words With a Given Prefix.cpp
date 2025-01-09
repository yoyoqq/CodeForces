class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (string& word : words){
            bool poss = true;
            if (pref.size() > word.size()) continue;
            for (int i=0; i<pref.size(); i++){
                if (pref[i] != word[i]){
                    poss = false;
                    break;
                } 
            }
            if (poss) count++;
        }
        return count;
    }
};