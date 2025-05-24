from collections import *
import math

class Solution:
    def sumOfLargestPrimes(self, s: str) -> int:
        # get all the primes 
        # check if its prime 
        # output: largest 3 
        # otherwise sum all 
        # else 0 
        def is_prime(num):
            if num == 1: return False
            is_prime = True
            for i in range(2, int(math.sqrt(num))+1):
                if num % i == 0:
                    is_prime = False
                    break
            return is_prime
        
        n = len(s)
        primes = []
        for i in range(n):
            for j in range(i+1, n+1):
                num = int(s[i:j])
                # print(num, is_prime(num))
                if is_prime(num):
                    primes.append(num)

        # sorted(primes, reverse=True)
        primes = list(set(primes))
        primes.sort(reverse=True)
        # print(primes)
        if len(primes) >= 3:
            return primes[0] + primes[1] + primes[2]
        elif len(primes) > 0:
            return sum(primes)
        else:
            return 0

# sol = Solution()
# print(sol.sumOfLargestPrimes("12234"))