class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        if k == 1: return 1
        # only need the remainder
        cur = 1
        sz = 1
        seen = set()
        while cur != 0:
            if cur in seen:
                return -1
            seen.add(cur)
            cur = (cur * 10 + 1) % k
            sz += 1
        
        return sz