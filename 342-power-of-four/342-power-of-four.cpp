class Solution {
public:
    bool isPowerOfFour(int n) {
        long long a = 1;
        while(a*4<=n){
            a*=4;
        }
        return a==n;
    }
};