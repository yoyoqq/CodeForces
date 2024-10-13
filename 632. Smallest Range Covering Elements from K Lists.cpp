class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();
        int left = nums[0][0], right = nums[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        int mx = INT_MIN, start = 0, end = INT_MAX;
        // 
        for (int i=0; i<nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});
            mx = max(mx, nums[i][0]);
        }
        while (pq.size() == nums.size()){
            auto [mn, indeces] = pq.top();
            pq.pop();
            int row = indeces.first, col = indeces.second;
            if (mx - mn < end - start){
                start = mn;
                end = mx;
            }
            if (col + 1 < nums[row].size()){
                int nextVal = nums[row][col+1];
                pq.push({nextVal, {row, col + 1}});
                mx = max(mx, nextVal);
            }
        }
        return {start, end};
        
        // int k = nums.size();
        // vector<vector<int>> groups(51); // put into groups 
        // // 1 2 3 4 5 6 ...  / index
        // // a   b   ab  ...  / gropu name (our case in numbers)
        // for (int i=0; i<k; i++){
        //     for (int j=0; j<nums[i].size(); j++){
        //         // cout << nums[i][j] << " ";
        //         groups[nums[i][j]].push_back(i);
        //     }
        // }
        // // brute force to contain k groups || 2 pointers 
        // // iterate gropus
        // int smallest = 100;
        // int mn = 100;
        // int mx = 0;
        // for (int right=0; right<51; right++){
        //     int cur_count = 100;
        //     vector<bool> seen_groups(51);
        //     for (int left; left<right; left++){
        //         // add 
        //         for (int& x : groups[left]){
        //             seen_groups[x] = true;
        //         }
        //         // check 
                
        //     }
            
        // }
        
        // two pointers too long...   :/    time complexity increases too much as well 
        // int left = 0;
        // for (int right=0; right<51; right++){
        //     // add from right 
        //     for (vector<int>& g : groups[right]){
        //         for (int& x : g){
        //             seen_groups.push_back(x);
        //         }
        //     }
        //     // check if move left, only if k count of each group is greater than 1 
        //     while (){
        //         left++;
        //         // remove from 
        //     } 
        //     // add to res 
        //     smallest = min(smallest, right - left)
        // }
    }

private:
    void print(vector<vector<int>>& groups){
        for (int i=0; i<51; i++){
            cout << "group " << i << endl;
            for (int j=0; j<groups[i].size(); j++){
                cout << groups[i][j] << " ";
            }
            cout << endl;
        }
    }
};