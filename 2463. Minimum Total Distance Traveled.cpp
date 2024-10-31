class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // TABULATION  
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factoryPos;
        for(auto& f : factory){
            for (int i=0; i<f[1]; i++){
                factoryPos.push_back(f[0]);
            }
        }
        int robotCount = robot.size(), factoryCount = factoryPos.size();
        vector<vector<long long>> dp(robotCount + 1, vector<long long>(factoryCount + 1, 0));

        // base case 
        for (int i=0; i<robotCount; i++){
            dp[i][factoryCount] = 1e13; // at the end finished  
        }
        for (int i=robotCount-1; i>=0; i--){
            for (int j=factoryCount-1; j>=0; j--){
                // get 
                long long assign = abs(robot[i] - factoryPos[j]) + dp[i+1][j+1];
                // skip
                long long skip = dp[i][j+1];
                dp[i][j] = min(assign, skip);
            }
        }
        return dp[0][0];
    }
};


// USING BRUTEFORCE DP SKIP NO SKIP RECURSION WITH MEMO 

    //     int robotCount = robot.size(), factoryCount = factoryPos.size();
    //     // save on memory dp 
    //     vector<vector<long long>> memo(robotCount, vector<long long>(factoryCount, -1));
    //     return calculate(0, 0, robot, factoryPos, memo);
    // }

    // long long calculate(int robotIdx, int factoryIdx, vector<int>& robot, vector<int>& factoryPos, vector<vector<long long>>& memo){
    //     if (robotIdx == robot.size()) return 0;
    //     if (factoryIdx == factoryPos.size()) return 1e14;
    //     if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];
    //     // take cur one 
    //     long long assign = abs(robot[robotIdx] - factoryPos[factoryIdx]) + calculate(robotIdx + 1, factoryIdx + 1, robot, factoryPos, memo);
    //     // skip current factoyr 
    //     long long skip = calculate(robotIdx, factoryIdx + 1, robot, factoryPos, memo);

    //     return memo[robotIdx][factoryIdx] = min(assign, skip);


// class Solution {
// public:
//     long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//         // brute force?/
//         // unpack factory
//         vector<int> fact;
//         for (int i=0; i<factory.size(); i++){
//             for (int j=0; j<factory[i][1]; j++){
//                 fact.push_back(factory[i][0]);
//             }
//         }
//         // for each robot get the smallest 
//         sort(robot.begin(), robot.end());
//         sort(fact.begin(), fact.end());
//         long long count = 0;
//         for (int i=0; i<robot.size(); i++){
//             long long cur = INT_MIN;
//             int idx = 0;
//             for (int j=0; j<fact.size(); j++){
//                 if (fact[j] == INT_MAX) continue;
//                 if (abs(robot[i] - fact[j]) < cur){
//                     cur = abs(robot[i] - fact[j]);
//                     idx = j;
//                 }
//             }
//             count += cur;
//             fact[idx] = INT_MAX;
//         }
//         return count;
//     }
// };


// class Solution {
// public:
//     long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
//         // for each robot assign the closest factory 
//         sort(robot.begin(), robot.end());
//         sort(factory.begin(), factory.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
//         // for each robot, get the closest factory, binary search 
//         long long count = 0;
//         for (int& r : robot){
//             // lower and upper compare which one is closest
//             auto lower = std::lower_bound(factory.begin(), factory.end(), std::vector<int>{r}, [](const std::vector<int>& a, const std::vector<int>& b) {
//                 return a[0] < b[0];
//             });
//             auto upper = std::upper_bound(factory.begin(), factory.end(), std::vector<int>{r}, [](const std::vector<int>& a, const std::vector<int>& b) {
//                 return a[0] < b[0];
//             });
//             // out of bounds 
//             long long distLower = (lower != factory.begin()) ? std::abs(r - (*(lower - 1))[0]) : LLONG_MAX;
//             long long distUpper = (upper != factory.end()) ? std::abs(r - (*upper)[0]) : LLONG_MAX;

//             cout << distLower << " " << distUpper << endl;
                
//             // use the closest one 
//             if (distLower < distUpper){
//                 count += distLower;
//             }else{
//                 count += distUpper;
//             }
//             // Reduce factory capacity after assigning it to a robot
//             if (lower != factory.end() && (*lower)[1] > 0) {
//                 (*lower)[1]--;
//             } else if (upper != factory.end() && (*upper)[1] > 0) {
//                 (*upper)[1]--;
//             }
//         }
//         // }
//         // if zero 
        
//         return count;
//     }

// private: 
    
// };