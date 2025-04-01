class Solution {
    private:
        vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        
    public:
        void gameOfLife(vector<vector<int>>& board) {
            // observation: only change if 1, 3, 4
            
            // in order to do in place 
            // two pass, assign diff variables
            // combinations 
            // dead     dead    0   0     
            // alive    alive   1   1
            // dead     alive   1   2 
            // alive    dead    0   3
            // do mod [i][j] to get cur state
            // second pass update 2 and 3 
            
            // dies: 1, 4 
            // live: 2-3
            // rep: 3 neigh live  
            int n = board.size(), m = board[0].size();
            vector<vector<int>> temp = board;
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                    // count neigh
                    int alive = 0;
                    for (auto [dx, dy] : directions){
                        int nx = dx + i, ny = dy + j;
                        if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] % 2 == 1) alive++;
                    }
                    if (board[i][j] % 2 == 1){
                        // alive dead 
                        if (alive <= 1 || alive >= 4) board[i][j] = 3;
                    }
                    // dead alive  
                    else{
                        if (alive == 3) board[i][j] = 2;
                    }
                }
            }
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                    if (board[i][j] == 2) board[i][j] = 1;
                    if (board[i][j] == 3) board[i][j] = 0;
                }
            }
        }
    };