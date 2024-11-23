class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // rotate 90 degrees 
        // vector<vector<char>> grid(box[0].size(), vector<char>(box.size()));
        int m = box.size(), n = box[0].size();
        vector<vector<char>> grid;
        for (int col=0; col<box[0].size(); col++){
            vector<char> cur;
            for (int row=box.size()-1; row>=0; row--){
                // grid[row][col] = box[row][col];
                cur.push_back(box[row][col]);
            }
            grid.push_back(cur);
        }
        // print(grid);
        // calculate gravity for stones 
        for (int col = 0; col < m; col++) {
            int spot = n - 1; 
            for (int row = n - 1; row >= 0; row--) {
                if (grid[row][col] == '*') {
                    spot = row - 1; 
                } else if (grid[row][col] == '#') {
                    grid[row][col] = '.';
                    grid[spot][col] = '#';
                    spot--;
                }
            }
        }


        return grid;


        // box.clear();
        // cout << endl;
        // for (int col=0; col<grid[0].size(); col++){
        //     vector<char> stack;
        //     // for (int row=grid.size()-1; row>=0; row--){
        //     for (int row=0; row<grid.size(); row++){
        //         // empty stone obstacle 
        //         // problem is when we find stone 
        //         if (grid[row][col] == '.' || grid[row][col] == '*'){
        //             stack.push_back(grid[row][col]);
        //         }
        //         // found stone, make it fall 
        //         else{
        //             int taken_out = 0;
        //             while (stack.size() && stack.back() == '.'){
        //                 taken_out++;
        //                 stack.pop_back(); 
        //             }
        //             stack.push_back('#');
        //             // push empty
        //             while (taken_out){
        //                 taken_out--;
        //                 stack.push_back('.');
        //             }
        //         }
        //     }
        //     box.push_back(stack);
        // } 
        // return box;
    }

    void print(vector<vector<char>>& grid){
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size();  j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

};