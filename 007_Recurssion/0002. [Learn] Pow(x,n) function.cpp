// Time  : O(N)
// Space : O(N)
class Solution {
public:
    double xRaisedn(double x, int n){
        if(n==0){
            return 1;
        }
        return x * xRaisedn(x, n-1);
    }

    double myPow(double x, int n) {
        double x_raisedTo_n = xRaisedn(x, abs(n));
        if(n<0){
            return 1/x_raisedTo_n;
        }
        return x_raisedTo_n;
    }
};