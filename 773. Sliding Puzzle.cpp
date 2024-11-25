class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<string> seen;
        string start = getBoard(board);
        queue<pair<string, int>> q;
        q.push({start, 0});
        seen.insert(start);
        while (q.size()){
            auto [cur, moves] = q.front(); q.pop();
            if (cur == target) return moves;
            int zeroIndex = cur.find('0'); 
            int x = zeroIndex / 3, y = zeroIndex % 3;

            for (auto& d : dir){
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= 2 || ny < 0 || ny >= 3) continue; // Out of bounds

                string next = cur;
                swap(next[x * 3 + y], next[nx * 3 + ny]);
                if (seen.count(next) == 0){
                    q.push({next, moves+1});
                    seen.insert(next);
                }
            }
        }
        return -1;
    }

private:
    string getBoard(vector<vector<int>>& board){
        string res;
        for (auto& row : board){
            for (int num : row){
                res += to_string(num);
            }
        }
        return res;
    }
};


// BRUTE FORCE TOO SLOW

// class Solution {
// public:
//     int slidingPuzzle(vector<vector<int>>& board) {
//         set<int> seen; 
//         int minMoves = INT_MAX; 
//         backtrack(board, seen, 0, minMoves);
//         return (minMoves == INT_MAX) ? -1 : minMoves;
//     }

// private:

//     vector<vector<int>> dir = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};

//     void backtrack(vector<vector<int>>& board, set<int>& seen, int cur_moves, int& min_moves){
//         int cur_board = getBoard(board);

//         // if visited 
//         if (seen.find(cur_board) != seen.end()){
//             return;
//         }
//         // sorted 
//         if (isSorted(board)){
//             min_moves = min(min_moves, cur_moves);
//         }
//         seen.insert(cur_board);
//         // zero
//         auto [zeroX, zeroY] = findZero(board);
//         // children 
//         for (auto d : dir){
//             int newX = zeroX + d[0];
//             int newY = zeroY + d[1];
//             if (newX >= 0 && newX < 2 && newY >= 0 && newY < 3) {
//                 swap(board[zeroX][zeroY], board[newX][newY]);
//                 backtrack(board, seen, cur_moves+1, min_moves);
//                 swap(board[zeroX][zeroY], board[newX][newY]);
//             }
//         }
//         seen.erase(cur_board);
//     }

//     bool isSorted(vector<vector<int>>& board){
//         int count = 1;
//         for (int i=0; i<2; i++){
//             for (int j=0; j<3; j++){
//                 if (i==1 && j == 2) continue;
//                 if (board[i][j] == count){
//                     count++;
//                 }else{
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     int getBoard(vector<vector<int>>& board){
//         int count = 0;
//         for (int i=0; i<2; i++){
//             for (int j=0; j<3; j++){
//                 count = count * 10 + board[i][j]; 
//             }
//         }
//         return count;
//     }

//     pair<int, int> findZero(vector<vector<int>>& board){
//         for (int i=0; i<2; i++){
//             for (int j=0; j<3; j++){
//                 if (board[i][j] == 0){
//                     return {i, j};
//                 }
//             }
//         }
//         return {-1, -1};
//     }

// };