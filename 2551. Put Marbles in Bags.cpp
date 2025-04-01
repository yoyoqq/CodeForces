class Solution {
    public:
        long long putMarbles(vector<int>& weights, int k) {
            // mark splits 
            int n = weights.size();
            vector<long long> splits;
            for (int i=0; i<n-1; i++){
                splits.push_back(weights[i] + weights[i+1]);
            }
            // get the max split 
            sort(splits.begin(), splits.end());
            for (int i=0; i<splits.size(); i++){
                cout << splits[i] << endl;
            }
            // get output 
            long long max = 0;
            long long min = 0;
            for (int i=0; i<k-1; i++){
                max += splits[n-2-i];
                min += splits[i];
            }
            return max - min;
        }
    };
    
    
    // class Solution {
    // public:
    //     long long putMarbles(vector<int>& weights, int k) {
    //         // the subarray from start and finish is always counted 
    //         // take the max and min ? 
    //         priority_queue<int> maxHeap;
    //         priority_queue<int, vector<int>, greater<int>> minHeap;
    //         for (int i=0; i<weights.size(); i++){
    //             maxHeap.push(weights[i]);
    //             minHeap.push(weights[i]);
    //             if (maxHeap.size()-1 > k) maxHeap.pop();
    //             if (minHeap.size()-1 > k) maxHeap.pop();
    //         }
    //         // diff 
    //         int max = 0;
    //         int min = 0;
    //         while (maxHeap.size()){
    //             int mx = maxHeap.top(); maxHeap.pop();
    //             int mn = minHeap.top(); minHeap.pop();
    //             max += mx;
    //             min += mn;
    //         }
    //         return max - min;
    //     }
    // };