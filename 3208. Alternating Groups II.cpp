class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            // colors += colors;
            colors.insert(colors.end(), colors.begin(), colors.end());
    
            int left = 0, count = 0;
            int size = (colors[0] == colors[n-1] ? n : n + k-1);
            for (int right=1; right<size; right++){
                // base case 
                if (colors[right] == colors[right-1]){
                    left = right;
                }
                if (right - left + 1 > k){
                    left++;
                }
                // count
                if (right - left + 1 == k) count++;
            }
            return count;
        }
    };