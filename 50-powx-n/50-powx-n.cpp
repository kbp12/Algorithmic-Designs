class Solution {
public:
    double solve(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = solve(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
    double myPow(double x, int N) {
        long long n = N;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return solve(x, n);
    }
};