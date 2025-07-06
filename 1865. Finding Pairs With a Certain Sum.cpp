class FindSumPairs {
public:
    map<int, int> freq1;
    map<int, int> freq2; 
    vector<int> nums2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums22) {
        for (auto& num : nums1){
            freq1[num]++;
        }
        for (auto& num : nums22){
            freq2[num]++;
            nums2.push_back(num);
        }
    }
    
    void add(int index, int val) {
        // remove element 
        freq2[nums2[index]]--;
        // add element
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        // if the same num X/Y
        for (auto& [x, v] : freq1){
            int y = tot - x;            
            ans += freq2[y] * v;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */