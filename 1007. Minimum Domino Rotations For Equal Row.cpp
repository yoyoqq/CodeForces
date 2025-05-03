class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            // another approach 
            // countA + countB + sameI == n
            
            
            // find the values that we can use 
            // there are only 2 poss numbers we can use 
            int n = tops.size();
            vector<int> dots(7, 0);
            for (int i=0; i<n; i++){
                if (tops[i] == bottoms[i]) dots[tops[i]]++;
                else{
                    dots[tops[i]]++;
                    dots[bottoms[i]]++;
                }
            }
            // only process the ones that have count N 
            int ans = 1e9;
            for (int i=1; i<dots.size(); i++){
                if (dots[i] != n) continue;
                // minimum count top/bot
                int top = 0, bot = 0;
                for (int j=0; j<n; j++){
                    if (i == tops[j] && tops[j] == bottoms[j]) {
                        top++;
                        bot++;
                    }
                    else if (tops[j] == i) top++;
                    else if (bottoms[j] == i) bot++;
                }
                // check bot as it can be repeated block, otherwise couting more 
                ans = min({ans, n-top, n-bot});
            }
            return (ans == 1e9 ? -1 : ans);
        }
    };