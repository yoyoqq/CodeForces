class LCA:
    def __init__(self, n: int, edges: List[int], root: int = 1):
        self.n = n
        self.LOG = n.bit_length()   # calculate number of levels needed for binary lifting log2(n)
        self.graph = defaultdict(list)
        # make graph 
        for u, v in edges:
            self.graph[u].append(v)
            self.graph[v].append(u)

        self.depth = [0] * (n + 1)  # store the depth for each node i 
        self.parent = [[-1] * self.LOG for _ in range(n + 1)]   # parent[i][k] store the 2^k ancestor node of i 

        self.dfs(root, -1)  # build parent and depth 
        self.build()        # build binary lifting 

    def dfs(self, u: int, p: int) -> None:  # recursive build depth and parent 
        self.parent[u][0] = p
        for v in self.graph[u]:
            if v != p:
                self.depth[v] = self.depth[u] + 1
                self.dfs(v, u)

    def get_depth(self, u: int) -> int:
        return self.depth[u]

    def build(self):
        # binary lifting step 
        for k in range(1, self.LOG):            # for all the powers 
            for u in range(1, self.n + 1):      # all the nodes 
                prev = self.parent[u][k - 1]
                if prev != -1:
                    self.parent[u][k] = self.parent[prev][k - 1]

    def query(self, u: int, v: int) -> int:
        # find the LCA 
        if self.depth[u] < self.depth[v]:
            u, v = v, u
        # till same level 
        for k in reversed(range(self.LOG)):
            if self.depth[u] - (1 << k) >= self.depth[v]:
                u = self.parent[u][k]
        if u == v:
            return u
        # move both at same time with log, under LCA 
        for k in reversed(range(self.LOG)):
            if self.parent[u][k] != self.parent[v][k]:
                u = self.parent[u][k]
                v = self.parent[v][k]
        return self.parent[u][0]

class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        MOD = 10 ** 9 + 7
        n = len(edges)
        lca = LCA(n + 1, edges)
        res = []
        for u, v in queries:
            r = lca.query(u, v)
            ne = lca.get_depth(u) + lca.get_depth(v) - lca.get_depth(r) * 2
            if ne == 0: res.append(0)
            else: res.append(2 ** (ne - 1) % MOD)
        return res