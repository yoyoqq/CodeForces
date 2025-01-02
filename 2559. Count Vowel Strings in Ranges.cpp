class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // get prefix 
        int n = words.size();
        vector<int> prefix(n+1, 0);
        for (int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + isVowel(words[i-1]);
        }
        // get for prefix 
        vector<int> ans;
        for (auto& query : queries){
            int left = query[0], right = query[1];
            ans.push_back(prefix[right+1] - prefix[left]);
        }
        return ans;
    }

    bool isVowel(string& word){
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        if (vowels.count(word[0]) && vowels.count(word[word.size()-1])) return true;
        return false;
    }
};