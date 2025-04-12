class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        if (n <= 2): return n

        # from the biggest value put all ones 
        num = (1 << n.bit_length()) - 1
        
        # n (permutations) + (generate from biggest n turn on bits) + zero        
        return n + (num - n) + 1