class Solution {
private:

    void count(char& c, int& x, int& y, int dir){
        if (c == 'U') y = y + 1*dir;
        if (c == 'D') y = y + -1*dir;
        if (c == 'L') x = x + -1*dir;
        if (c == 'R') x = x + 1*dir;
    }
    
public:
    int distinctPoints(string s, int k) {
        // cur position 
        int x = 0, y = 0;
        for (char& c : s){
            count(c, x, y, 1);
        }
        // sliding window 
        int left = 0;
        set<pair<int, int>> seen;
        for (int right=0; right<s.size(); right++){
            char c = s[right];
            count(c, x, y, 1);
            // move left 
            if (right-left>=k){
                count(s[left], x, y, -1);
                left++;
            }
            // output 
            if (right-left+1==k){
                seen.insert({x, y});
            }
        }
        return seen.size(); 
    }
};
