class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        // rows 
        for (int i=0; i<n; i++){
            set<char> seen;
            for (int j=0; j<n; j++){
                if (board[i][j] == '.') continue;
                if (seen.find(board[i][j]) != seen.end()){
                    cout << i << " " << j << endl;
                    return false;    
                }
                seen.insert(board[i][j]);
            }
        }
        // cols 
        for (int j=0; j<n; j++){
            set<char> seen;
            for (int i=0; i<n; i++){
                if (board[i][j] == '.') continue;
                if (seen.find(board[i][j]) != seen.end()){
                    return false;    
                }
                seen.insert(board[i][j]);
            }
        }
        // 3 x 3 
        for (int i=0; i<n; i+=3){
            for (int j=0; j<n; j+=3){
                // this block
                cout << i << " " << j << endl; 
                set<char> seen;
                for (int x=i; x<i+3; x++){
                    for (int y=j; y<j+3; y++){
                        if (board[x][y] == '.') continue;
                        if (seen.find(board[x][y]) != seen.end()){
                            return false;    
                        }
                        seen.insert(board[x][y]);
                    }
                }                
            }
        }
        return true;
    }
};