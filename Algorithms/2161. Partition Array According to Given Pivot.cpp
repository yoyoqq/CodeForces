class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left, right, output; 
        int count = 0;
        for (int& num : nums) {
            if (num == pivot) count++;
            else if (num < pivot) left.push_back(num);
            else right.push_back(num);
        }
        // output 
        for (int& num : left) output.push_back(num);
        for (int i=0; i<count; i++) output.push_back(pivot);
        for (int& num : right) output.push_back(num);
        return output;
    }
};