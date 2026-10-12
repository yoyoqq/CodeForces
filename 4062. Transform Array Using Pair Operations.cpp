class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        // take the ones that are != target 
        // 1 3 
        // 0 4 
        long long count1 = 0, count2 = 0;
        for (int i=0; i<source.size(); i++) {
            if (source[i] == target[i]) continue;
            else {
                count1 += source[i];
                count2 += target[i];
            }
        }
        return count1 == count2; 
    }
};