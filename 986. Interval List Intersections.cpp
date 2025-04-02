/*

1. read problem and think about test cases 
2. ways to sovle it -> choose the optimal 
3. implementation
4. optimization/refactoring
5. reflect on problem and issues 


- join both and sort O(n log n)
    join tasks

- two pointers i,j 
    check if any is inside the other 
        if not, move the smaller start  
        if it is inside, 
            calculate -> end - start 

test cases
    separate (no relation)
    in mid/ half 
    just start/end -> 1 pos 
*/

class Solution {
    public:
        vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
            int n = firstList.size(), m = secondList.size();
            int i = 0, j = 0; 
            vector<vector<int>> ans;
    
            while (i<n && j<m){
                int sx = firstList[i][0], ex = firstList[i][1];
                int sy = secondList[j][0], ey = secondList[j][1];
                int left = max(sx, sy), right = min(ex, ey);
                // if y is inside x 
                if (sx <= sy && sy <= ex){
                    ans.push_back({left, right});
                }
                // x is inside Y 
                else if (sy <= sx && sx <= ey){
                    ans.push_back({left, right});
                }
                // move only pointer that is smaller on END 
                if (ex <= ey){
                    i++;
                }else{
                    j++;
                }
            }
            return ans;
        }
    };