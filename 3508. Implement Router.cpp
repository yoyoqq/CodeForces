class Router:

    def __init__(self, memoryLimit: int):
        self.limit = memoryLimit
        self.dq = deque()               # queue
        self.exists = set()             # existing packets
        self.dl = defaultdict(deque)    # count for each destination
    
    def _removeOldest(self):
        oldest = self.dq.popleft()
        self.exists.discard(oldest)
        self.dl[oldest[1]].popleft()
        return oldest

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        if (source, destination, timestamp) in self.exists: return False
        if len(self.dq) == self.limit:
            self._removeOldest()
        self.dq.append((source, destination, timestamp))
        self.exists.add((source, destination, timestamp))
        self.dl[destination].append(timestamp)
        return True

    def forwardPacket(self) -> List[int]:
        if not self.dq: return []
        return self._removeOldest()

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        # timestamps are always in increasing order 
        tList = self.dl[destination]
        l, r = 0, len(tList)-1
        # lower bound
        while l <= r:
            mid = l + (r-l) // 2
            if tList[mid] >= startTime: r = mid - 1
            else: l = mid + 1
        leftMost = l

        # upper bound 
        l, r = 0, len(tList)-1
        while l <= r:
            mid = l + (r-l) // 2
            if tList[mid] <= endTime: l = mid + 1
            else: r = mid - 1
        rightMost = r
        return rightMost - leftMost + 1

"""
// class Router {
// public:
//     queue<vector<int>> queue;
//     set<vector<int>> packets;
//     map<int, multiset<int>> times;
//     int limit;
    
//     Router(int memoryLimit) {
//         limit = memoryLimit;        
//     }
    
//     bool addPacket(int source, int destination, int timestamp) {
//         vector<int> packet = {source, destination, timestamp};
//         if (packets.find(packet) != packets.end()) return false;
//         // erase if too large 
//         if (limit == queue.size()){
//             vector<int> front = queue.front();
//             queue.pop();
//             packets.erase(front);
//             times[front[1]].erase(times[front[1]].find(front[2]));
//         }
//         // insert 
//         packets.insert(packet);
//         queue.push(packet);
//         times[destination].insert(timestamp);
//         return true;
//     }
    
//     vector<int> forwardPacket() {
//         if (queue.size()){
//             vector<int> front = queue.front();
//             queue.pop();
//             packets.erase(front);
//             times[front[1]].erase(times[front[1]].find(front[2]));

//             return front;
//         }
//         return {};
//     }
    
//     int getCount(int destination, int startTime, int endTime) {
//         auto& ms = times[destination];
//         return distance(ms.lower_bound(startTime), ms.upper_bound(endTime));
    
//     }

// };

// /**
//  * Your Router object will be instantiated and called as such:
//  * Router* obj = new Router(memoryLimit);
//  * bool param_1 = obj->addPacket(source,destination,timestamp);
//  * vector<int> param_2 = obj->forwardPacket();
//  * int param_3 = obj->getCount(destination,startTime,endTime);
//  */


"""

# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)