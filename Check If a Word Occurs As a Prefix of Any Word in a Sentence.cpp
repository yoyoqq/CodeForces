class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence += ' ';
        string cur;
        int ans = 1;
        for (int i=0; i<sentence.size(); i++){
            if (sentence[i] == ' '){
                if (cal_pref(cur, searchWord)){
                    return ans;
                }
                ans++;
                cur = "";
            }else{
                cur += sentence[i];
            }
        }
        return -1;
    }

private:
    bool cal_pref(string cur, string searchWord){
        if (searchWord.size() > cur.size()) return false;
        if (cur.substr(0, searchWord.size()) == searchWord) return true;
        return false;
    }
};