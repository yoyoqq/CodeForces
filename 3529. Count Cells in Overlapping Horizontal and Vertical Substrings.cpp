class Solution:
    def countCells(self, grid: List[List[str]], pattern: str) -> int:
        m = len(grid)
        n = len(grid[0])
        x = len(pattern)

        # horizontal
        hor = ""        
        for arr in grid:
            hor += "".join(arr)
        res1 = []
        pr = 0
        for i in range(len(hor)-len(pattern)+1):
            if hor[i:i+x] == pattern:   # string matching 
                res1.append((max(i, pr), i+x))   # start, end   maximums 
                pr = i + x
        if len(res1) == 0: return 0 # if none found is not possbile 
        res = set()
        for a, b in res1:
            for i in range(a, b):
                res.add((i//n, (i%n)))  # coordinates in grid add in between
        
        # vertical 
        var = ""
        for i in range(n):
            for j in range(m):
                var += grid[j][i]
        res2 = set()
        prev = 0
        for i in range(len(var)-x+1):
            if var[i:i+x] == pattern:
                for j in range(max(prev,i), i+x):   # mark the range 
                    res2.add((j%m, j//m))
                prev = i+x
        res = res.intersection(res2)
        return len(res)

# class Solution:
#     def countCells(self, grid: List[List[str]], pattern: str) -> int:
#         # cannot wrap around (limt)
#         # evaluate independently row col 
#         # row col check string matching -> boyer more ? brute force 
#         n = len(grid)
#         m = len(grid[0])
#         # check horizontally string matching, flatten
#         horizontal = [False for _ in range(n*m)]
#         horizontal_grid = ""
#         for i in range(n):
#             for j in range(m):
#                 horizontal_grid += grid[i][j]
        
#         idx = 0
#         for i in range(n*m):
#             if horizontal_grid[i] == pattern[idx]:
#                 idx += 1
#                 if idx == len(pattern):
#                     # Pattern matched
#                     for j in range(i, i-len(pattern), -1):
#                         horizontal[j] = True
#                     idx = 1 if horizontal_grid[i] == pattern[0] else 0
#             else:
#                 idx = 1 if horizontal_grid[i] == pattern[0] else 0

#         # check for vertical 
#         vertical_grid = ""
#         for j in range(m):
#             for i in range(n):
#                 vertical_grid += grid[i][j]
#         vertical = [False for i in range(n*m)]
#         idx = 0
#         for i in range(n*m):
#             if vertical_grid[i] == pattern[idx]:
#                 idx += 1
#                 if idx == len(pattern):
#                     idx = 1 if vertical_grid[i] == pattern[0] else 0
#                     for j in range(i, i-len(pattern), -1):
#                         vertical[j] = True
#             else:
#                 idx = 1 if vertical_grid[i] == pattern[0] else 0
#         # convert horizontal and vertical to its n m 
#         # how ? take m chunks, only need one to be the same 
#         # print(horizontal_grid, vertical_grid)
#         # print(horizontal)
#         # print(vertical)
#         final_vertical = [[False for _ in range(m)] for __ in range(n)]
#         for idx in range(n*m):
#             j = idx // n
#             i = idx % n
#             final_vertical[i][j] = vertical[idx]

#         # print(horizontal)
#         # print(final_vertical)
#         count = 0
#         hor_pos = 0
#         for i in range(n):
#             for j in range(m):
#                 if (horizontal[hor_pos] and final_vertical[i][j]):
#                     count += 1
#                 hor_pos += 1
#         return count

        
        
#         # chunks = 
#         # final_horizontal = []
#         # final_vertical = []
#         # temporal_horizontal = []
#         # temporal_vertical = []
#         # for i in range(n * m):
#         #     temporal_horizontal.append(horizontal[i])
#         #     temporal_vertical.append(vertical[i])
#         #     chunks += 1
#         #     if (chunks == m):
#         #         chunks = 0
#         #         final_horizontal.append(temporal_horizontal)
#         #         final_vertical.append(temporal_vertical)
#         #         temporal_horizontal = []
#         #         temporal_vertical = []

#         # print(final_horizontal)
#         # print(final_vertical)
