class Solution {
public:

    int m[100000] = {};
    const int pr[65] = {
        2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
        43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
        103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
        173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
        241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};


    long long dfs(int i, int p, vector<vector<int>>& al, vector<int>& nums) {
        int n = nums[i], fn = 1;
        // square free kernel 
        for (int i = 0; i < 65 && n >= pr[i]; ++i)
            for (; n % pr[i] == 0; n /= pr[i])
                fn = fn % pr[i] == 0 ? fn / pr[i] : fn * pr[i];
        // add to the kernel, count ancestors 
        long long res = m[n * fn]++;
        // children 
        for (int j : al[i])
            if (j != p)
                res += dfs(j, i, al, nums);
        // backtrack 
        --m[n * fn];
        return res;
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> al(n);
        for (const auto& e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        return dfs(0, 0, al, nums);
    }
};

// int m[100000] = {};
// const int pr[65] = {
//     2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
//     43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
//     103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
//     173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
//     241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};

//     long long dfs(int i, int p, map<int, vector<int>>& graph, vector<int>& nums){
//         // base case 
//         int n = nums[i], fn = 1;
//         for (int i=0; i<65 && n >= pr[i]; i++)
//             for (; n%pr[i] == 0; n/=pr[i])
//                 fn = fn % pr[i] == 0 ? fn / pr[i] : fn * pr[i];
//         long long res = m[n*fn]++;
//         for (int j : graph[i]){
//             if (j != p) res += dfs(j, i, graph, nums);
//         }
//         --m[n*fn];
//         return res;
//     }


//     long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
//         // build graph 
//         map<int, vector<int>> graph;
//         for (vector<int> edge : edges){
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
//         // iterate dfs -> how to optimzize ancestors ? 
//         // return dfs(n, graph, nums, 0, -1, {});
//         return dfs(0, 0, graph, nums);
//     }
// };
