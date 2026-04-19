function minimumDistance(nums: number[]): number {
    let freq: Map<number, number[]> = new Map()
    for (let i = 0; i < nums.length; i++) {
        let val = nums[i]
        if (!freq.has(val)) {
            freq.set(val, [])
        }
        freq.get(val)!.push(i)
    }
    let ans: number = Number.MAX_SAFE_INTEGER

    for (const [key, value] of freq) {
        if (value.length <= 2) continue
        for (let x = 2; x < value.length; x++) {
            let i = value[x-2]
            let j = value[x-1]
            let k = value[x]
            let calc = Math.abs(i - j) + Math.abs(i - k) + Math.abs(j - k)
            console.log(i, j, k, calc)
            ans = Math.min(ans, calc)
        }
    }
    return ans === Number.MAX_SAFE_INTEGER ? -1 : ans
};