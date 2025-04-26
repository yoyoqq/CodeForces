class Solution:
    def findCommonResponse(self, responses: List[List[str]]) -> str:
        # remove duplicates 
        # get max count 
        freq = defaultdict(int)
        mx_count = 0
        for response in responses:
            seen = set()
            for r in response:
                if r not in seen:
                    seen.add(r)
                    freq[r] += 1
                    mx_count = max(mx_count, freq[r])
        # get the max count 
        ans = []
        for response, response_count in freq.items():
            # print(response, response_count)
            if response_count == mx_count:
                ans.append(response)
        ans.sort()
        # print(ans)
        return ans[0]