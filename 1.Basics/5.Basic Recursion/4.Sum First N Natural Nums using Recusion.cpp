long long get_sum(int n){
    if(n<=0) return 0;
    return n + get_sum(n-1);
}

long long sumFirstN(long long n) {
    long long res = get_sum(n);
    return res;
}