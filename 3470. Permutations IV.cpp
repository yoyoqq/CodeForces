class Solution:
    def permute(self, n: int, k: int) -> List[int]:
        ans = []
        vals = list(range(1, n+1))
        want = 1
        for t in range(n):
            ways = factorial(n-1-t>>1) * factorial(n-t>>1)

            for i, v in enumerate(vals):
                if v%2 != want and (t or n%2):
                    continue
                if k<=ways:
                    break
                k -= ways
            else:
                return []
            
            ans.append(vals.pop(i))
            want = ans[-1] & 1 ^ 1
        return ans