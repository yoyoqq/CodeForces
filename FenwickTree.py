# https://www.youtube.com/watch?v=uSFzHCZ4E-8
class FenwickTree:
    def __init__(self, size):
        self.tree = [0] * (size + 1)

    def update(self, index, delta):
        index += 1
        while index <= len(self.tree) - 1:
            self.tree[index] += delta
            index += index & -index

    def query(self, index):
        index += 1
        res = 0
        while index > 0:
            res += self.tree[index]
            index -= index & -index
        return res

        

class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        pos2, reversedIndexMapping = [0] * n, [0] * n
        for i, num2 in enumerate(nums2):
            pos2[num2] = i
        for i, num1 in enumerate(nums1):
            reversedIndexMapping[pos2[num1]] = i
        
        tree = FenwickTree(n)
        res = 0
        for value in range(n):
            pos = reversedIndexMapping[value]
            left = tree.query(pos)
            tree.update(pos, 1)
            right = (n-1-pos) - (value-left)
            res += left * right
        return res
            
# class Solution:
#     def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
#         # right upper bound 
#         def binary_search(num):
#             left = 0 
#             right = len(nums2) - 1
#             idx = 0
#             while left <= right:
#                 mid = left + (right - left) // 2
#                 # if 
#                 if nums2[mid] <= num:
#                     idx = mid
#                     left = mid + 1
#                 else:
#                     right = mid - 1
#             return idx 

#         # join 
#         n = len(nums1)
#         arr = []
#         for i in range(n):
#             arr.append((nums1[i], nums2[i]))
#         # sort 
#         arr.sort()
#         # nums1.sort()
#         nums2.sort()
#         print(arr, nums1, nums2)
#         # get triplets x < y < z
#         # 2 for loops, check if x < y for pos2, bs for its index on nums2 -> get min to res 
#         count = 0
#         for i in range(n):
#             for j in range(i+1, n):
#                 if arr[i][1] < arr[j][1]:
#                     left = n - j - 1       # nums1 pos 
#                     right = n - binary_search(arr[j][1]) - 1
#                     print(arr[i], arr[j], left, right)
#                     count += min(left, right)
#         return count