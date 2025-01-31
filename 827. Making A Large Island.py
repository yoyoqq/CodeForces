class Solution:
    
    def largestIsland(self, grid: List[List[int]]) -> int:
        # 1. group islands 
        # 2. join if possible 
        def make_group(i, j):
            nonlocal group
            # all as same group
            cur_size = grid[i][j]
            stack = []
            stack.append((i, j))
            seen = set()
            seen.add((i, j))
            while len(stack):
                x, y = stack.pop()
                island_group[x][y] = group
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in seen and grid[nx][ny] == 1:
                        seen.add((nx, ny))
                        stack.append((nx, ny))
                        cur_size += grid[nx][ny]
            group += 1
            # same size 
            seen.clear()
            stack.append((i, j))
            while len(stack):
                x, y = stack.pop()
                # island_group[x][y] = group
                island_size[x][y] = cur_size
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in seen and grid[nx][ny] == 1:
                        seen.add((nx, ny))
                        stack.append((nx, ny))
            return
        
        directions = [[0,1], [1,0], [-1,0], [0,-1]]
        n = len(grid)
        m = len(grid[0])
        island_size = [[0]*m for i in range(n)]
        island_group = [[0]*m for i in range(n)]
        group = 1 
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and island_group[i][j] == 0:
                    make_group(i, j)    # bfs/dfs expand 
        
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    # take from bottom up left and right 
                    cur_sum = 0
                    seen = set()
                    for dx, dy in directions:
                        x = dx + i
                        y = dy + j
                        if (0 <= x < n and 0 <= y < m) and island_group[x][y] not in seen:
                            seen.add(island_group[x][y])
                            cur_sum += island_size[x][y]
                    ans = max(ans, cur_sum)
        
        # print(island_group)
        # print(island_size)
        # print(group)
        if island_size[0][0] == m*n:
            return m * n
        return ans + 1