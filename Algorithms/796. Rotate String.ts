function rotateString(s: string, goal: string): boolean {
    // if (s.length !== goal.length) return false
    // s = s + s
    // return s.includes(goal)

    if (s.length !== goal.length) return false
    let n = goal.length
    s = s + s
    for (let i = 0; i < s.length; i++) {
        if (s.substring(i, i+n) === goal) return true
        // console.log(s, i, n, i+n, s.substring(i, i+n))
    }
    return false
};