class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        n = len(status)
        have_key = status[:]
        have_box = [False] * n
        seen = [False] * n
        
        q = deque()
        ans = 0

        for box in initialBoxes:
            have_box[box] = True
            if have_key[box]:
                q.append(box)
                seen[box] = True
                ans += candies[box]

        while q:
            box = q.popleft()
            for key in keys[box]:
                have_key[key] = True
                if not seen[key] and have_box[key]:
                    q.append(key)
                    seen[key] = True
                    ans += candies[key] 
            for bx in containedBoxes[box]: 
                have_box[bx] = True
                if not seen[bx] and have_key[bx]:
                    q.append(bx)
                    seen[bx] = True
                    ans += candies[bx]
        return ans

# class Solution:
#     def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
#         # open as many boxes as we can bfs till no change 
#         ans = 0
#         visited = set()
#         boxes = initialBoxes
#         while boxes:
#             temp = []
#             # go to all the candies 
#             for box in boxes:
#                 if box in visited: continue
#                 if not status[box]:
#                     temp.append(box)
#                 else:
#                     # we can use the box 
#                     visited.add(box)
#                     ans += candies[box]
#                     for key in keys[box]:
#                         status[key] = 1
#                     for contained in containedBoxes[box]:
#                         temp.append(contained)
#             # same after the iteration 
#             if temp == boxes:
#                 break
#             boxes = temp        
#         return ans