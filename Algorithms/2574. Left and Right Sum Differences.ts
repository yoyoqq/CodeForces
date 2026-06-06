function leftRightDifference(nums: number[]): number[] {
    let right: number = 0
    let left: number = 0
    for (let i = 0; i < nums.length; i++) {
        right += nums[i]
    }
    let arr: number[] = []
    for (let i = 0; i < nums.length; i++) {
        right -= nums[i]
        arr.push(Math.abs(right-left))
        left += nums[i]
    }
    return arr
};