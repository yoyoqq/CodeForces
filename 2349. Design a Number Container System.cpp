class NumberContainers {
    public:
        map<int, int> container;
        map<int, priority_queue<int, vector<int>, greater<int>>> smallest_idx;
        NumberContainers() {
        }
        
        void change(int index, int number) {
            container[index] = number;
            smallest_idx[number].push(index);
        }
        
        int find(int number) {
            while (smallest_idx[number].size() && number != container[smallest_idx[number].top()]){
                // cout << smallest_idx[number].top() << " " << container[smallest_idx[number].top()] << endl;
                smallest_idx[number].pop();
            }
            if (smallest_idx[number].size() == 0) return -1;
            return smallest_idx[number].top();
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */