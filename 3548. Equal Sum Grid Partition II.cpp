class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        def check(grid):
            seen = set()
            top = 0 
            for i, r in enumerate(grid):
                seen |= set(r)  # get whole row 
                top += sum(r)   # sum whole row 
                bot = total - top
                # if can take edges spikes 
                if top - bot in [0, grid[0][0], grid[0][-1], grid[i][0]]: return True
                # can take any on the middle 
                if len(grid[0]) > 1 and i > 0 and top - bot in seen: return True
            return False
        
        total = sum(sum(r) for r in grid)
        # first pass 
        # we need to reverse because we are only checking one way, top down
        # not bot - top 
        if check(grid) or check(grid[::-1]): return True
        # second pass 
        # * star -> unpacks the grid 
        grid = list(zip(*grid)) # transpose the grid 
        if check(grid) or check(grid[::-1]): return True
        return False