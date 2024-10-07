class Solution {
public:
    int minLength(string s) {
        vector<char> stack;
        for (char& c : s){
            // append
            stack.push_back(c);
            // check if we have AB or CD
while (stack.size() >= 2 && ((stack[stack.size()-2] == 'A' && stack[stack.size()-1] == 'B') || (stack[stack.size()-2] == 'C' && stack[stack.size()-1] == 'D'))) {
                stack.pop_back();
                stack.pop_back();
            }
        }
        return stack.size();
    }
};