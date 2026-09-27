class Solution {
public:
    void print(stack<char> stack) {
        string ans = "";
        while (stack.size()) {
            ans += stack.top();
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    string reverseParentheses(string s) {
        stack<char> stack;
        for (char& c : s) {
            if (c != ')') {
                stack.push(c);
            } 
            else {
                string cur = "";
                while (stack.top() != '(') {
                    cur += stack.top(); 
                    stack.pop();
                }
                stack.pop();
                // append 
                for (char& cur_c : cur) stack.push(cur_c);
                // print(stack);
            } 
        }
        // output 
        string ans = "";
        while (stack.size()) {
            ans += stack.top();
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};