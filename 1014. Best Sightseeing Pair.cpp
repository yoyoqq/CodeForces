class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int left = 0;
        int mx = INT_MIN;
        for (int right=1; right<values.size(); right++){
            mx = max(mx, values[right] + values[left] + left - right);
            // compare which left is gonna be bigger 
            if (values[left] + left <= values[right] + right){
                left = right;
            }
        }
        return mx;
    }
};