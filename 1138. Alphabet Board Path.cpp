class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        # board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]
        # create the board as coordinates x y 
        board = dict()
        cur = 'a'
        for i in range(5):
            for j in range(5):
                board[cur] = (i, j)
                cur = chr(ord(cur) + 1) 
        board['z'] = (5, 0)
        # iterate target 
        def find_moves(character, x, y):
            res = ""
            dx, dy = board[character]
            # if at Z go up first 
            if x == 5 and y == 0 and character != 'z':
                x -= 1
                res += 'U'
            # y direction goes first due to Z
            for i in range(abs(y-dy)):
                res += ('L' if dy < y else 'R')
            # x direction 
            for i in range(abs(x-dx)):
                res += ('U' if dx < x else 'D')
            return res, dx, dy

        x = 0
        y = 0
        ans = ""
        for t in target:
            temp = find_moves(t, x, y)
            ans += temp[0] + "!"
            x = temp[1]
            y = temp[2]
        return ans
