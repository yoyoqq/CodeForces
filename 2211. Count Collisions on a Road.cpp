class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size(), l = 0, r = n - 1, res = 0;
        // move pointers 
        while (l < n && directions[l] == 'L') l++;
        while (r >= 0 && directions[r] == 'R') r--;
        
        for (int i=l; i<=r; i++){
            if (directions[i] != 'S') res++;
        }
        return res;
    }
};

// class Solution {
// public:
//     bool options(char& stack, char& dir){
//         // R L -> 2   -> RRRRLLLL
//         // S L -> 1   -> SLLLLLL
//         // R S -> 1   -> RRRRRRS    RL
//         return false;
//     }

//     int countCollisions(string directions) {
//         int collisions = 0;
//         stack<char> stack;
//         for (char& dir : directions){
//             // R L 
//             if (stack.size() && stack.top() == 'R' && dir == 'L'){
//                 dir = 'S';
//                 collisions += 2;
//                 stack.pop();
//             }
//             // R S 
//             while (stack.size() && stack.top() == 'R' && dir == 'S'){
//                 collisions++;
//                 stack.pop();
//             }
//             // S L 
//             if (stack.size() && stack.top() == 'S' && dir == 'L'){
//                 collisions++;
//                 dir = 'S';
//             }
//             stack.push(dir);
//         }
//         return collisions;
//     }
// };