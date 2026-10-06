class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<bool> stack;
        int ans = 0;
        for (char& c : s) {
            if (c == '(') {
                stack.push(1);
            }
            // close 
            else {
                if (stack.size() == 0) ans++;
                else stack.pop();
            }
        }    
        return ans + stack.size();
    }
};