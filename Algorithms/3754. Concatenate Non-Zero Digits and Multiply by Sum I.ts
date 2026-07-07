function sumAndMultiply(n: number): number {
    // non zero * sum 
    let non_zero = 0
    let sum: number = 0
    while (n) {
        let x = n % 10
        n = Math.floor(n / 10)
        if (x !== 0) non_zero = non_zero * 10 + x
        sum += x
        // console.log(x, n)
    }
    // console.log(non_zero, sum)
    non_zero = Number(non_zero.toString().split("").reverse().join(""));
    console.log(non_zero)
    return non_zero * sum
};