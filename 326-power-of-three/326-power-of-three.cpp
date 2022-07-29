class Solution {
public:
    bool isPowerOfThree(int n) {
        long long a = 1;
        while(a*3<=n){
            a*=3;
        }
        return a==n;
    }
};