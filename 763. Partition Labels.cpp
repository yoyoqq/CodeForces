class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int n = s.size();
            map<char, int> last_char;
            for (int i=0; i<n; i++){
                last_char[s[i]] = i;
            }
            // make partitions 
            vector<int> partitions; 
            // two pointers left/right
            int left = 0, right = 0;
            for (int i=0; i<n; i++){
                right = max(right, last_char[s[i]]);
                if (i == right){
                    partitions.push_back(i - left + 1);
                    left = right + 1;
                }
            }
            return partitions;
        }
    };