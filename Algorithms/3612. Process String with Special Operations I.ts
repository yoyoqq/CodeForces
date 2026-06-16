function processStr(s: string): string {
    let ans: string[] = []
    for (const c of s) {
        if (c == '*') {
            ans.pop()
        }
        else if (c == '#') {
            ans = [...ans, ...ans]
        }
        else if (c == '%') {
            ans.reverse()
        }
        else {
            ans.push(c)
        }
    }
    let output: string = ""
    for (let c of ans) {
        output += c
    }
    return output
};