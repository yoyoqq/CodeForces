class Solution {
    public:
        int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
            int low = bounds[0][0], high = bounds[0][1];
            int ans = 0;
            for (int i=1; i<original.size(); i++){
                int diff = original[i] - original[i-1];
                low = max(bounds[i][0], low + diff);
                high = min(bounds[i][1], high + diff);
            }
            return max(high-low+1, 0);
        }
    };