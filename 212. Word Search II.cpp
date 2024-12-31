// class Solution {
// public:

//     bool bfs(vector<vector<char>>& board, string& word, int x, int y){
//         if (board[x][y] != word[0]) return false; 

//         // iteratively, bfs 
//         int rows = board.size();
//         int cols = board[0].size();
//         set<pair<int, int>> seen;
//         seen.insert({x, y});
//         queue<tuple<int, int, int>> pq;
//         pq.push({x, y, 0});
//         while (pq.size()){
//             auto [curX, curY, idx] = pq.front(); pq.pop();

//             if (idx == word.size() - 1) return true; 

//             for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, -1}, {0, 1}}) {
//                 int newX = curX + dx;
//                 int newY = curY + dy;

//                 if (newX < 0 || newY < 0 || newX >= rows || newY >= cols) continue;
//                 if (seen.count({newX, newY}) || board[newX][newY] != word[idx + 1]) continue;

//                 // Add to the queue and mark as seen
//                 pq.push({newX, newY, idx + 1});
//                 seen.insert({newX, newY});
//             }
//         }
//         return false;
//     }



//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         // dp problem 
//         // for each word, dfs if matching start word 
//         map<char, vector<string>> first_char;
//         for (auto& word : words){
//             first_char[word[0]].push_back(word);
//         }
//         set<string> seen;
//         for (int i=0; i<board.size(); i++){
//             for (int j=0; j<board[0].size(); j++){
//                 // for all the matching 
//                 for (string& word : first_char[{board[i][j]}]){
//                     if (seen.find(word) != seen.end()) continue;
//                     if (bfs(board, word, i, j)){
//                         seen.insert(word);
//                     }
//                 }
//             }
//         }
//         // res
//         vector<string> res;
//         for (auto word : seen){
//             res.push_back(word);
//         }
//         return res;
//     }
// };