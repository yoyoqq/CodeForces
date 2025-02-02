class Solution {
public:
    bool check(vector<int>& nums) {
        // since first its sorted and then rotated
        // increases and then decreases and increases again 
        // up, 1 down, up
        int n = nums.size();
        auto arr = nums; sort(arr.begin(), arr.end());
        for (int x=0; x<=100; x++){
            bool poss = true;
            for (int i=0; i<nums.size(); i++){
                if (arr[i] != nums[(i+x) % n]){
                    poss = false;
                    break;
                }
            }
            if (poss) return true;
        }
        return false;
    }
}; 