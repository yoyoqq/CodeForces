    struct TrieNode{
        unordered_map<char, TrieNode*> children;
        string word = "";
    };

    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for (string& word : words){
            TrieNode* node = root;
            for (char c : word){
                if (!node->children.count(c)){
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->word = word;
        }
        return root;
    }