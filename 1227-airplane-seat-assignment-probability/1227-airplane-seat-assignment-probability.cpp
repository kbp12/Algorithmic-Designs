class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans;
        if(n==1) ans= (double)1;
        else ans = (double)1/2;
        return ans;
    }
};