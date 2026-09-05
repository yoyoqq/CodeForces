class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # sort 
        intervals = intervals + [newInterval]
        intervals = sorted(intervals)
        # algo sort 
        arr = [intervals[0]]
        for i in range(1, len(intervals)):
            # merge
            if arr[-1][1] >= intervals[i][0]:
                arr[-1][1] = max(arr[-1][1], intervals[i][1]) 
            # append
            else:
                arr.append(intervals[i])
        return arr