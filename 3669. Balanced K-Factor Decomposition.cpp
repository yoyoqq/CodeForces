class Solution:
    def minDifference(self, n: int, k: int) -> List[int]:
        def dfs(num, parts):
            # return factor 
            if parts == 1:
                return (num, )
                
            min_diff = float("inf")
            best_factors = None

            # try every factor 
            for i in range(1, int(num**0.5)+1):
                if num % i == 0:
                    quot = num // i

                    # get all the factors recursve 
                    remaining_factors = dfs(quot, parts-1)
                    # build array + current i
                    current_factors = (i,) + remaining_factors 

                    sorted_factors = tuple(sorted(current_factors))
                    diff = sorted_factors[-1] - sorted_factors[0]

                    if diff < min_diff:
                        min_diff = diff
                        best_factors = sorted_factors 
                        if min_diff == 0:
                            break
            return best_factors
        
        return list(dfs(n, k))
        
# class Solution:
#     def minDifference(self, n: int, k: int) -> List[int]:
#         # multiples of n -> divide by prime numbers 
#         arr = []
#         power = 2 
#         while n != 1:
#             while n % power == 0:
#                 arr.append(power)
#                 n /= power
#             power += 1
        
#         # need to place ones on the arr
#         if len(arr) < k:
#             return arr[-1] - 1
#         # same size cannot do any better 
#         elif len(arr) == k: 
#             return arr[-1] - arr[0]
#         # need to join ? how ? 
#         arr = sort(ans)

            
#         return arr