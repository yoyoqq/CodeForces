class Solution {
    public:
        string getHappyString(int n, int k) {
            vector<string> happy_strings = find_happy(n);
            sort(happy_strings.begin(), happy_strings.end());
            if (k-1 >= happy_strings.size()) return "";
            return happy_strings[k-1];
        }
    
    private:
        vector<char> happy = {'a', 'b', 'c'};
        vector<string> find_happy(int& n){
            stack<string> stack;
            for (char h : happy) stack.push(string(1, h));
            vector<string> res; 
            while (stack.size()){
                string cur = stack.top(); stack.pop();
                if (cur.size() == n){
                    res.push_back(cur);
                    continue;
                }
                for (char h : happy){
                    if (cur.back() == h) continue;
                    stack.push(cur + h);
                }
            }
            return res;
        }
    };