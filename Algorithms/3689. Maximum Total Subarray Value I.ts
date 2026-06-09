function maxTotalValue(nums: number[], k: number): number {
    let mn = 1e9
    let mx = 0
    for (let i=0; i<nums.length; i++) {
        mx = Math.max(mx, nums[i])
        mn = Math.min(mn, nums[i])
    }
    return (mx - mn) * k
};