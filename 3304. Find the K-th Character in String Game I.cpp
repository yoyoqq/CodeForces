class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k){
            // take each and increase +1
            string next = word;
            for (int i=0; i<next.size(); i++){
                if (next[i] == 'z') next[i] = 'a';
                else{
                    next[i]++;
                }
            }
            word += next;
        }
        cout << word;
        return word[k-1];
    }
};