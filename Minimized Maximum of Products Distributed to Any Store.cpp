// Minimized Maximum of Products Distributed to Any Store


class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        // binary search for how much give to each store 
        int left = 1;
        int right = 0;
        for (int& q : quantities) right = max(right, q);
        int x = INT_MAX;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (possibleX(mid, quantities, n)){  // move if we need more 
                x = min(x, mid);
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return x; 
    }

private:
    bool possibleX(int target, vector<int>& quantities, int& n){
        // check for each if possible to match 
        int count = 0;
        for (int& q : quantities){
            count += (q / target) + (q % target != 0);
        }
        return (count <= n) ? true : false;
    }
};

// class Solution {
// public:
//     int minimizedMaximum(int n, vector<int>& quantities) {
//         // how to distribute from quantities
//         // make distribution as fair as possible 
//         // we want to split into diff nums 
//         // use heapq to get the max num

//         // how to split pq.top? 
//         // while pq.top() > pq2.top() && x + pq.size > n
//         priority_queue<int> pq;
//         for(int& x : quantities) pq.push(x);
//         while (pq.size() != n){
//             int greatest = pq.top(); pq.pop();
//             // get the closest divisoin 
//             int division = 2; 
//             while (greatest/division + (greatest%division != 0) + pq.size() > n){
//                 division++;
//             }
//             // check if next is the same 
//             if (greatest/division == greatest/(1+division)){
//                 division++;
//             }
//             cout << pq.size() << " " << division << endl;
//             // append to pq
//             for (int i=0; i<division; i++){
//                 pq.push(greatest/division);
//             }
//             if (greatest%division != 0){
//                 pq.push(greatest%division);
//             }
//         }
//         while (pq.size()){
//             cout << pq.top() << " " ;
//             pq.pop();
//         }
//         return pq.top();
//     }
// };