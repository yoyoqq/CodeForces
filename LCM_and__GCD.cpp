int gcd(int a, int b){
    while (b != 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}