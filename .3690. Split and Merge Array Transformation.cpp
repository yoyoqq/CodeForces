class Solution:
    def minSplitMerge(self, nums1: List[int], nums2: List[int]) -> int:
        # print(nums1)
        # i = 1
        # j = 2
        # left = nums1[:i]
        # mid = nums1[i:j]
        # right = nums1[j:]
        # print(left, mid, right)
        # return 0
        # def check(arr):
        #     val = True
        #     for i in range(n):
        #         val &= (arr[i] == nums2[i])
        #     return val


        def put_locations(arr, mid):
            for i in range(len(arr)):
                temp = []
                # left side 
                for j in range(i):
                    temp.append(arr[j])
                # mid side 
                for j in range(len(mid)):
                    temp.append(mid[j])
                # right side 
                for j in range(i, len(arr)):
                    temp.append(arr[j])
                # print(arr, mid, temp)
                if len(temp) == n and tuple(temp) not in seen:
                    seen.add(tuple(temp))
                    bfs.append(temp)

        # find all the splits 
        def partition(arr):
            # all the partitions 
            for i in range(n):
                for j in range(i+1, n+1):
                    left = arr[:i]
                    mid = arr[i:j]
                    right = arr[j:]
                    # print(left, mid, right)
                    # put at all locations 
                    put_locations(left+right, mid)

        # try all possible combinations 
        n = len(nums1)
        bfs = deque()
        bfs.append(nums1)
        seen = set()
        seen.add(tuple(nums1))
        level = 0
        while bfs:
            size = len(bfs)
            for _ in range(size):
                arr = bfs.popleft()
                if arr == nums2:
                    return level
                partition(arr)
            level += 1
            # print(level, bfs)
        return -1 

                