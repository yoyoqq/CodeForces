class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        for (int i=0; i<s.size(); i+=2){
            if (s[i] != s[i+1]) count++;
        }
        return count;
    }
};


class Solution {
public:
    int minChanges(string s) {
        int res = 0;
        int cur = s[0] == ('1' - '0');
        int count = 0;
        for (char& c : s){
            if ((c - '0') == cur){
                count++;
            }else{
                // even 
                if (count % 2 == 0){
                    count = 1;
                }
                // odd 
                else{
                    res++;
                    count = 2;
                }
                cur = (cur == 1) ? 0 : 1;
            }
        }
        return res;
    }
};
