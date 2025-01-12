class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 == 1) return false;
        // change to own representation
        string word;
        for (int i=0; i<s.size(); i++){
            if (locked[i] == '0'){
                word += '*';
            }else{
                word += s[i];
            }
        }
        // how to check if we can close parenthesis 
        stack<int> helper;
        stack<int> open;
        for (int i=0; i<word.size(); i++){
            char w = word[i];
            if (w == '(') open.push(i);
            else if (w == '*') helper.push(i);
            else{
                if (open.size()) open.pop();
                else if (helper.size()) helper.pop();
                else{
                    return false;
                }
            }
        }
        // opening + helper
        while (!helper.empty() && !open.empty()){
            if (helper.top() > open.top()){
                helper.pop();
                open.pop();
            }else{
                return false;
            }
        }
        return open.empty();
    }
};
        // int open = 0;
        // int close = 0;
        // for (int i=0; i<word.size(); i++){
        //     char w = word[i];
        //     char ww = word[word.size() - i-1];
        //     if (w == '(' || w == '*'){
        //         open++;
        //     }else{
        //         open--;
        //     }
        //     if (ww == ')' || ww == '*'){
        //         close++;
        //     }else{
        //         close--;
        //     }
        //     if (open < 0 || close < 0){
        //         return false;
        //     }
        // }


        // // check if correct 
        // int parenthesis = 0;
        // for (char& w : word){
        //     if (w == '*') continue;
        //     if (w == '(') parenthesis++;
        //     else if (')' && parenthesis) parenthesis--;
        // }
        // cout << parenthesis << endl;
        // if (parenthesis) return false;