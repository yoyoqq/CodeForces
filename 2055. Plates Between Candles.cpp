/*

reflection
    couldve spent more time simplying the problem 
    think about hte algorithms 

    for having the groups, rather than having all the size sbuset
    which is always gonan be usualls ythe case, just have the bars 

    the nfor each qeury find the bars 
    get the stars in between 

*/

class Solution {
    public:
        vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
            // vector<int> a = {1, 3, 5};
            // int lower = lower_bound(a.begin(), a.end(), 4) - a.begin();
            // cout << lower << endl;
    
            // make groups where the bars are 
            // for each query, prefix sum all the bars from one to another 
            int n = s.size();
            vector<int> bars;
            vector<int> prefix(n+1, 0);
            for (int i=0; i<n; i++){
                if (s[i] == '|'){
                    bars.push_back(i);
                }
                prefix[i+1] = prefix[i] + (s[i] == '*');
            }
    
            vector<int> ans;
            for (int i=0; i<queries.size(); i++){
                int l = queries[i][0], r = queries[i][1];
                // left -> rightmost     lwoerbound 
                // right -> leftmost     lower? 
                int left = lower_bound(bars.begin(), bars.end(), l) - bars.begin();
                int right = upper_bound(bars.begin(), bars.end(), r) - bars.begin() - 1;
                // ans.push_back(prefix[bars[right]] - prefix[bars[left]]);
                if (left <= right && left < bars.size() && 0 <= right)
                    ans.push_back(prefix[bars[right]] - prefix[bars[left]]);
                else{
                    ans.push_back(0);
                }
            }
            return ans;
        }
    };