class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        count = 0
        row = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                # left most col 
                if j == 0:
                    row[i][j] = mat[i][j]
                # take prev 
                else:
                    if mat[i][j] == 0:
                        row[i][j] = 0
                    else:
                        row[i][j] = row[i][j-1] + 1
                
                # count 
                cur = row[i][j]
                for k in range(i, -1, -1):
                    if mat[k][j] == 0:
                        break
                    cur = min(cur, row[k][j]) # if the size decreases in the rectangle while going up 
                    count += cur
        return count 