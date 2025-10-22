

def getDigits(x, digit):
    while x:
        digit.append(x % 10)
        x //= 10

        

dp = [[[-1 for i in range(2)] for j in range(180)] for k in range(20)]
def digitSum(index, sumof, tight, digit):
    if index == -1:
        return sumof
    if dp[index][sumof][tight] != -1 and tight != 1:
        return dp[index][sumof][tight]
    ret = 0
    # calculate range val 
    k = digit[index] if tight else 9 
    for i in range(0, k+1):
        newTight = tight if digit[index] == i else 0
        ret += digitSum(index-1, sumof+i, newTight, digit)
    if not tight:
        dp[index][sumof][tight] = ret
    return ret



def rangeDigitSum(a, b):
    digitA = []
    # store digits 
    getDigits(a-1, digitA)
    # find sum of digits 1 to a-1 
    ans1 = digitSum(len(digitA)-1, 0, 1, digitA)
    
    digitB = []
    getDigits(b, digitB)
    ans2 = digitSum(len(digitB)-1, 0, 1, digitB)
    return ans2-ans1

a, b = 123, 1024
# print("digit sum given range : ", rangeDigitSum(a, b))
