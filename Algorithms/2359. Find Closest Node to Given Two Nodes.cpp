class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // FIND THE MAXIMUM DISTANCE FROM BOTH NODES
        // MAXIMAZE DISTANCE 
        
        // bfs for node1 
        // bfs for node2 
        int n = edges.size();
        vector<int> distance1(n, -1); 
        vector<int> distance2(n, -1); 
        bfs(edges, distance1, node1);
        bfs(edges, distance2, node2);
        // find minimum distance for node 2 
        int ans = -1;
        // int maximum = -1;
        int minimum = 1e9;
        for (int i=0; i<n; i++){
            if (distance1[i] != -1 && distance2[i] != -1) {
                int maxDist = max(distance1[i], distance2[i]);
                if (maxDist < minimum) {
                    minimum = maxDist;
                    ans = i;
                }
            }
        }
        return ans;
    }

private:
    void bfs(vector<int>& edges, vector<int>& distance, int node){
        set<int> seen;
        queue<pair<int, int>> bfs; 
        bfs.push({node, 0});
        distance[node] = 0;
        seen.insert(node);
        while (bfs.size()){
            auto [cur, lvl] = bfs.front(); bfs.pop();
            distance[cur] = lvl;
            if (edges[cur] != -1 && seen.find(edges[cur]) == seen.end()){
                seen.insert(edges[cur]);
                bfs.push({edges[cur], lvl+1});
            }
        }
    }
};



// class Solution {
// public:
//     int closestMeetingNode(vector<int>& edges, int node1, int node2) {
//         // make graph 
//         // node1 maximum distance 
//         // node2 minimum distance 
//         // there WONT exists multiple answers 
//         // 1. find the nodes that node1 can go to 
//         // 2. iterate node2, if seen -> return
//         set<int> seen;
//         int cur = node1;
//         bool is_node2 = false;
//         while (cur != -1 && seen.find(cur) == seen.end()){
//             if (cur == node2) {is_node2=true; break;}
//             seen.insert(cur);
//             cur = edges[cur];
//         }
//         // iterate node2, if in seen return 
//         cur = node2;
//         set<int> seen2;
//         bool is_node1 = false;
//         while (cur != -1 && seen2.find(cur) == seen2.end()){
//             if (seen.find(cur) != seen.end()) return cur;
//             seen2.insert(cur);
//             cur = edges[cur];
//         }
//         // return (is_node2 ? node2 : -1);
//         if (is_node1) return node1;
//         if (is_node2) return node2;
//         return -1;
//     }
// };c