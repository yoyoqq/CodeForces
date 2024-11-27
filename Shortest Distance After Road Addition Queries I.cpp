class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        # create graph
        graph = defaultdict(list)
        for i in range(n-1):
            graph[i].append(i+1)
        # iterate queries
        res = []
        for x, y in queries:
            graph[x].append(y)
            # calculate res 
            queue = deque([(0, 0)])  # start from node 0 with distance 0
            count = float('inf')
            found = False
            visited = [False] * n
            visited[0] = False

            while queue and not found:
                top, cur = queue.popleft()
                if top == n - 1:
                    count = cur
                    found = True
                    break
                # children
                for child in graph[top]:
                    if not visited[child]:
                        visited[child] = True
                        queue.append((child, cur+1))
                
            res.append(count if found else -1)
        return res 