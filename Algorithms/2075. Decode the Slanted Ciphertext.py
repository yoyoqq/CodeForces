class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        # pass to rows col 
        cols = len(encodedText) // rows 
        arr = []
        temp = []
        for e in encodedText:
            temp.append(e)
            if len(temp) == cols:
                arr.append(temp)
                temp = []
        
        # print(arr)
        # build up str 
        output = ""
        for i in range(cols):
            # iterate directional down 
            row = 0 
            col = i 
            while row < rows and col < cols:
                output += arr[row][col]
                row += 1
                col += 1
        
        output = output.rstrip()
        return output