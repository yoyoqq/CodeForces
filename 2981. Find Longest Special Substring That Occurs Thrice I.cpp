class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> count;        // char, sbstr length -> count 
        int len = 0;
        for (int i=0; i<s.size(); i++){
            char chr = s[i];
            len = 0;
            for (int j=i; j<s.size(); j++){
                if (chr == s[j]){
                    len++;
                    count[{chr, len}]++;
                }else{
                    break;
                }
            }
        }
        // freq >= 3 
        int ans =0 ;
        for (auto i : count){
            int sz = i.first.second;
            cout << i.second <<  " " << sz << endl;
            if (i.second >= 3 && sz > ans) ans = sz;
        }
        if (ans == 0) return -1;
        return ans;
    }
};