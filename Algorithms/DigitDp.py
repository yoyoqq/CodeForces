# DIGIT DP 
# Problem: Count numbers in a range [L, R] whose digits sum to a given value S.

# constraints: 1 <= a <= b <= 10^18

# 3 variables: idx, tight, sum 
# 1. idx: current index value 
# 2. tight: is the range restricted limited by the upper bound
# 3. sum: store sum of digits. we are gonna have up to 9*18 = 162 possible values 



# idx, sum, tight 
dp = [[[-1 for i in range(2)] for j in range(180)] for k in range(20)]

# x = 1234
# digit = [4, 3, 2, 1] 
def getDigits(x, digit):
    while x: 
        digit.append(x % 10)
        x //= 10

def digitSum(idx: int, sm: int, tight: bool, digit: list[int]):
    # base case 
    if idx == -1:
        return sm
    
    # if we have seen it 
    # ? why tight != 1, at 1 we are constrained due to upper bound 
    if dp[idx][sm][tight] != -1 and tight != 1:
        return dp[idx][sm][tight]
    
    k = digit[idx] if tight else 9 
    res = 0
    for i in range(k+1):
        # ? are we still at the prefix or we relaxed 
        newTight = tight if digit[idx] == i else 0 
        
        res += digitSum(idx-1, sm+i, newTight, digit)
        
    # memo 
    # tight == 0 
    if not tight:
        dp[idx][sm][tight] = res
        
    return res

def rangeDigitSum(a, b):
    digitA = []
    # ? why a-1 
    # sum from a to b, but at end b - (a - 1) to not count a off 
    getDigits(a-1, digitA)
    ans1 = digitSum(len(digitA)-1, 0, 1, digitA)
    
    digitB = []
    getDigits(b, digitB)
    ans2 = digitSum(len(digitB)-1, 0, 1, digitB)
    return ans2 - ans1

# 122, 1023 
a, b = 123, 1024
print(rangeDigitSum(a, b))  # Output: Count of numbers in range [a, b] whose digit sum is S