class Solution {
public:
    string removeSubstring(string s, int k) {
        string ans = "";
        vector<pair<char, int>> stack;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '('){
                if (stack.size() && stack.back().first == '('){
                    stack.back().second++;
                }else{
                    stack.push_back({'(', 1});
                }
            } 
            else{
                if (stack.size() && stack.back().first == ')'){
                    stack.back().second++;
                }else{
                    stack.push_back({')', 1});
                }
            }
            // if the last 2 top are () == k then remove them 
            while (stack.size() >= 2 && stack[stack.size()-2].first == '(' && stack[stack.size()-2].second >= k && stack[stack.size()-1].first == ')' && stack[stack.size()-1].second >= k){
                auto close = stack.back(); stack.pop_back();
                auto open = stack.back(); stack.pop_back();
                close.second -= k;
                open.second -= k;
                if (open.second) stack.push_back({'(', open.second});
                if (close.second) stack.push_back({'(', close.second});
            }
        }
        for (auto [k, v] : stack){
            for (int i=0; i<v; i++) ans += k;
            // cout << k << " " << v << endl;
        } 
        return ans;
    }
};


// ((()))(
