class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        // count of each num
        map<int, int> freq;
        for (int& num : nums){
            freq[num]++;
        }
        // times a num appears 
        map<int, vector<int>> times;   // freq, [num]
        for (auto& [k, v] : freq){
            times[v].push_back(k);
        }
        // output 
        for (int& num : nums){
            if (times[freq[num]].size() == 1) return num;
        }
        return -1;
    }
};