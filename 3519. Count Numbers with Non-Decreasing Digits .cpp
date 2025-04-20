class Solution:
    def countNumbers(self, l: str, r: str, b: int) -> int:
        MOD = 10**9 + 7

        # Convert decimal‐string x into its base‐b digit‐string.
        def convert(x_str: str) -> str:
            x = int(x_str)
            if x == 0:
                return "0"
            if b == 10:
                return str(x)
            digits = []
            while x > 0:
                digits.append(str(x % b))
                x //= b
            return "".join(reversed(digits))

        # Prepare bounds in base‐b digit‐string form
        left_dec  = str(int(l) - 1)
        left_s    = convert(left_dec)
        right_s   = convert(r)

        # count all the nums that are smaller than X 
        @cache
        def dp(idx: int, num_s: str, tight: bool, last: int) -> int:
            # idx: current digit pos
            # num_s: the bound‐string (base‐b digits)
            # tight: are we still matching the prefix?
            # last: the previous digit we placed
            if idx == len(num_s):
                return 1
            total = 0
            upper = int(num_s[idx]) if tight else (b - 1)
            for d in range(last, upper + 1):
                total += dp(
                    idx + 1,
                    num_s,
                    tight and (d == upper),
                    d
                )
            return total % MOD

        return (dp(0, right_s, True, 0) - dp(0, left_s, True, 0)) % MOD
