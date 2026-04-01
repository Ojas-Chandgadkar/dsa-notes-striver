// The greatest common divisor (gcd) of two numbers 'n' and 'm' 
// is the largest positive number that divides both 'n' and 'm' without leaving a remainder.
//     Example:
//     Input: 'n' = 6, 'm' = 4
//     Output: 2
//     Explanation:
//     Here, gcd(4,6) = 2, because 2 is the largest positive integer that divides both 4 and 6.




int calcGCD(int n, int m){
    
    for(int i=(n<=m)?n:m; i>0; --i){
        if(n%i==0 && m%i==0) return i;
    }

    return -1;
}