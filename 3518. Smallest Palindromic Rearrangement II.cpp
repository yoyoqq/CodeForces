class Solution:
    def smallestPalindrome(self, s: str, K: int) -> str:
        # Put characters into frequency map 
        freq = defaultdict(int)
        for i in range(len(s)):
            freq[s[i]] += 1

        # Get middle character if there is one with odd count
        mid = ""
        for key, val in freq.items():
            if val % 2 == 1:  # Check for odd frequency
                mid = key
                break

        # Get half of the palindrome 
        halfFreq = [0 for _ in range(26)]
        halfLength = 0
        for key, val in freq.items():
            halfFreq[ord(key) - ord('a')] = val // 2
            halfLength += val // 2

        maxK = 1000001

        def binom(n, k):
            if k > n:
                return 0
            if k > n - k:
                k = n - k
            res = 1
            for i in range(1, k + 1):
                res = res * (n - i + 1) // i
                if res >= maxK:
                    return maxK
            return res

        def multinomial(counts):
            tot = sum(counts)
            res = 1
            for cnt in counts:
                res *= binom(tot, cnt)
                if res >= maxK:
                    return maxK
                tot -= cnt
            return res

        totalPerms = multinomial(halfFreq)
        if K > totalPerms:
            return ""  # Impossible to form such a palindrome

        left = ""
        for _ in range(halfLength):     # length 
            for c in range(26):         # for every char  
                if halfFreq[c] > 0:     # try to put c?
                    halfFreq[c] -= 1
                    perms = multinomial(halfFreq)   # try using the C?
                    if perms >= K:      # at least k, means its in the group
                        left += chr(c + ord('a'))
                        break
                    else:
                        K -= perms          # adjust K to find the c
                        halfFreq[c] += 1

        return left + mid + left[::-1]

# class Solution:
#     def smallestPalindrome(self, s: str, k: int) -> str:
#         freq = defaultdict(int)
#         for char in s:
#             freq[char] += 1
#         # get the one thats alone 
#         odd = ""
#         left = ""
#         for key, value in freq.items():
#             if value == 1: odd = key
#             else:
#                 temp = ""
#                 for i in range(value//2):
#                     temp += key
#                 left += temp
#         left = "".join(sorted(left))
#         if (len(freq) == 1): return "";  # also for 2   
#         print(left)
        
#         # move the first to the last
#         # move the second to last .. 
#         def parse(leftt):
#             return leftt + odd + "".join(reversed(leftt))

#         seen = set()
#         n = len(left)
#         temp = left
#         for i in range(n):    # move the 0 to the ith pos 
#             cur_chr = left[i]
#             left = temp[:i] + temp[i+1:]
#             print(temp,i, cur_chr, left )
#             for j in range(len(left)):           # place around 0 to n        
#                 cur_val = left[:j] + cur_chr + left[j:]
#                 seen.add(cur_val)
#                 if (len(seen) == k): break 
#             if (len(seen) == k): break 
#             left = temp
        
#         arr = list(seen)
#         arr.sort()
#         print(arr)
#         return parse(arr[-1])