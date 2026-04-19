function strip_str(s: string): string {
    // output: string = ""
    // front 
    let i = 0
    // for (; i < s.length; i++) {
    //     if (s[i] !== ' ') break;
    // }
    // s = s.substring(i)
    // back
    i = s.length - 1
    for (; i >= 0; i--) {
        if (s[i] !== ' ') break
    }
    s = s.substring(0, i + 1)
    // console.log(s)
    return s
}

function decodeCiphertext(encodedText: string, rows: number): string {
    let cols: number = encodedText.length / rows
    let arr: string[][] = []
    let temp: string[] = []
    for (const e of encodedText) {
        temp.push(e)
        if (temp.length === cols) {
            arr.push(temp)
            temp = []
        }
    }
    let output: string = ""
    // console.log(arr)
    for (let i = 0; i < cols; i++) {
        let row = 0
        let col = i
        while (row < rows && col < cols) {
            // console.log(arr[row][col])
            output += arr[row][col]
            row += 1
            col += 1
        }
    }
    // strip
    output = strip_str(output)
    // output = output.trim()
    return output
};