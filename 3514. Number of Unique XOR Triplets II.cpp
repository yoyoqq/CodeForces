class Solution { 
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        unordered_set<int> all_pairs;
        unordered_set<int> temp_pairs;

        // get i/j and ans 
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                temp_pairs.insert(nums[i] ^ nums[j]);
            }
            all_pairs.insert(nums[i]);
        }
        // find k
        for (const int& pair : temp_pairs){
            for (int& num : nums){
                all_pairs.insert(pair ^ num);
            }
        }
        return all_pairs.size();
    }
};


/*
        n = len(nums)
        if n <= 2: return n
        
        all_pairs = set()
        temp_pairs = set()
        
        for i in range(n):
            for j in range(n):
                temp_pairs.add(nums[i] ^ nums[j])
            all_pairs.add(nums[i])

        for pair in temp_pairs:
            for k in nums:
                all_pairs.add(pair ^ k)
        
        return len(all_pairs)
*/