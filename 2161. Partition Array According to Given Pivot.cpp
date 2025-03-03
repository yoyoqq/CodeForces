class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> a;
            int same = 0;
            for (int num : nums){
                if (num == pivot) same++;
                else if (num < pivot) a.push_back(num);
            }
            for (int i=0;i<same;i++){
                a.push_back(pivot);
            }
            for (int num : nums){
                if (num > pivot) a.push_back(num);
            }
            return a;
        }
    };