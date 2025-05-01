class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            // binary search, how many m tasks can we complete with m workers 
            // pick m easiest and m strongest 
            sort(tasks.begin(), tasks.end());        
            sort(workers.begin(), workers.end());        
            int l = 0, r = tasks.size();
            while (l < r){
                // do the K easiest tasks 
                int mid = (l + r + 1) /2;
                if (possible(tasks, workers, pills, strength, mid)){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            return l;
        }
    
    private:
        bool possible(vector<int>& tasks, vector<int>& workers, int pills, int& strength, int k){
            vector<int> w = workers;
            if (k > workers.size()) return false;
            // assign to workers from strongest, they can do the most amount of work 
            for (int i=k-1; i>=0; i--){
                // we dont need pill
                if (tasks[i] <= w.back()){
                    w.pop_back();
                }
                else if (pills){
                    int del_pos = lower_bound(w.begin(), w.end(), tasks[i]-strength) - w.begin();
                    if (del_pos == w.size()) return false;
                    pills--;
                    w.erase(w.begin()+del_pos); 
                }
                else{
                    return false;
                }
            }
            return true;
        }
    };
    
    
    // class Solution {
    // public:
    //     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    //         // take without pills and then with pills 
    //         sort(tasks.begin(), tasks.end());        
    //         sort(workers.begin(), workers.end());        
    //         int n = tasks.size(), m = workers.size();
    //         int j = 0;
    //         // without pills 
    //         for (int X : tasks) cout << X << " "; cout << endl;
    //         for (int X : workers) cout << X << " "; cout << endl;
    
    //         int count = 0;
    //         for (int i=n-1; i>=0; i--){
    //             while (j < m && workers[j] < tasks[i]){
    //                 j++;
    //             }       
    //             if (j >= m) break;
    //             if (workers[j] >= tasks[i]){
    //                 count++;
    //                 tasks[i] = -1;
    //                 workers[j] = -1;
    //             }   
    //             j++;
    //         }
    //         cout << count << endl;
    //         j = 0;
    //         for (int i=0; i<n; i++){
    //             if (tasks[i] == -1) continue;
    //             while (j < m && workers[j] == -1) j++;            
    //             if (j >= m || pills == 0) break;
    //             if (workers[j] + strength >= tasks[i]){
    //                 count++;
    //                 pills--;
    //             }
    //             j++;
    //         }
    //         cout << count << endl;
    //         return count;
    //     }
    // };
    
    
    // class Solution {
    // public:
    //     int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    //         sort(tasks.begin(), tasks.end());        
    //         sort(workers.begin(), workers.end());        
    //         int j = 0, count = 0;
    //         for (int i=0; i<tasks.size(); i++){
    //             while (j < workers.size() && !((workers[j] >= tasks[i]) || (pills > 0 && workers[j] + strength >= tasks[i]))){
    //                 // cout << (workers[j] < tasks[i]) << " " << (pills > 0 && workers[j] + strength < tasks[i]) << endl;
    //                 j++;
    //             }            
    //             // cout << endl;
    //             // cout << "IDX: " << i << " " << j << endl;
    //             if (j >= workers.size()) break;
    //             // take with pill or without 
    //             if (workers[j] >= tasks[i]) count++;
    //             else if (pills > 0 && workers[j] + strength >= tasks[i]){
    //                 count++;
    //                 pills--;
    //             }
    //             j++;
    //         }
    //         return count;
    //     }
    // };