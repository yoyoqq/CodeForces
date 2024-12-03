class Solution {
public:
    bool isPossible(vector<int>& target) {
        // init all [1,1,1,1,1,1,1...]
        // sum(all) = x
        // repeat 
        // sorting and working alwys with the first value doesnt work, there are comb that need smaller nums 
        // from topics hint is heapq try simulating the process 
        // reverse the process 
        
        // reverse engineering 
        // last digit formed by all the digits - x 


        // new problme, tle on [100000000, 1]
        // how to solve ? 
        // use % 
        // take second biggest, substract till smaller 
        // or, while smaller take off by * n 

        // we can reverse the problem. the ccurrent is based on the previous step 
        priority_queue<int> pq;
        long long sm = 0;
        for (int& t : target){
            pq.push(t);
            sm += t;
        }

        while (pq.top() != 1){
            int cur_mx = pq.top(); pq.pop();
            sm -= cur_mx; 
            // false?
            if (sm < 1 || cur_mx <= sm){
                return false;
            }
            cur_mx %= sm;
            sm += cur_mx;
            pq.push(cur_mx ? cur_mx : sm);
        }
        return true;
        
        
        
        // reverse till empty 
        // while (pq.size()){
            // int cur_mx = pq.top(); pq.pop();
            // // int sec_mx = pq.top();
            // int new_val = cur_mx - (sm - cur_mx);
            // sm = cur_mx;
            // // cout << cur_mx << " " << new_val << endl;
            // if (new_val <= 0){
            //     return false;
            // }
            // if (new_val != 1){
            //     pq.push(new_val);
            // }
        // }
        // return true;
    }
};