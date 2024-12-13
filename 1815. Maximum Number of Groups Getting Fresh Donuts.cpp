class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        # 3 observations 
        # 1. Take out the groups divisible by batchSize
        n = len(groups)
        groups = [group % batchSize for group in groups if group % batchSize]
        ans = n - len(groups)

        # 2. Take out pairs divisible by batchSize
        freq = Counter(groups)

        for num in range(1, batchSize):
            matchNum = batchSize - num
            if matchNum >= batchSize:
                continue
            if matchNum == num:
                match = freq.get(num, 0) // 2
            else:
                match = min(freq.get(num, 0), freq.get(matchNum, 0))
            ans += match
            freq[num] -= match
            freq[matchNum] -= match

        # 3. Remaining groups for brute force
        @lru_cache(None)
        def dp(remain, groups):
            if not groups:
                return 0
            ans = 0
            for i, group in enumerate(groups):
                nextGroups = groups[:i] + groups[i+1:]
                nextRemain = (remain + group) % batchSize
                ans = max(ans, (remain == 0) + dp(nextRemain, tuple(nextGroups)))
            return ans

        newGroups = []
        for num, cnt in freq.items():
            newGroups += [num] * max(0, cnt)

        return ans + dp(0, tuple(newGroups))
