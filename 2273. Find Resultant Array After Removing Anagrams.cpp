class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i=1; i<words.size(); i++){
            string left = ans.back(); sort(left.begin(), left.end());
            string right = words[i]; sort(right.begin(), right.end());
            if (left != right) ans.push_back(words[i]);
        }
        return ans;
        
        
        
        // !!!!!!!!!!!!!!!!!!!!!!!!! IM TROLLIGN :) ........................ smh 
        // map<string, string> mapper;
        // for (string w : words){
        //     string copy = w;
        //     sort(copy.begin(), copy.end());
        //     if (mapper.find(copy) == mapper.end())
        //         mapper[copy] = w;
        // }
        // vector<string> ans;
        // for (auto [k, v] : mapper){
        //     ans.push_back(v);
        // }
        // return ans;
    }
};
