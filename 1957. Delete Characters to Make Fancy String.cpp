class Solution {
public:
    string makeFancyString(string s) {
        // IF 3 CONSC changes use this code, otherwise we can loook behind 2 chars and compare 
        int cur_count = 0;
        char cur_char = '0';
        string res = "";
        for (char& c : s){
            // new char 
            if (cur_char != c){
                cur_char = c;
                cur_count = 1;
                res += c;
            }
            // same char 
            else if (cur_char == c && cur_count < 2){
                cur_count++;
                res += c;
            }
        }
        return res; 
    }
};