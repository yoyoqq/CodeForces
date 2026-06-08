function pivotArray(nums: number[], pivot: number): number[] {
    let left: number[] = []
    let right: number[] = []
    let count = 0
    for (let i=0; i<nums.length; i++) {
        if (pivot === nums[i]) count++
        else if (nums[i] < pivot) left.push(nums[i])
        else right.push(nums[i])
    }
    // output 
    let output: number[] = []
    for (var num of left) output.push(num)
    for (let i=0; i<count; i++) output.push(pivot)
    for (var num of right) output.push(num)
    return output
};