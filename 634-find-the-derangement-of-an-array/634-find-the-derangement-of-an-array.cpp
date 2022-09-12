class Solution {
public:
    int findDerangement(int n) {
        if(n==1) return 0;
        int first = 0, second = 1, mod = 1e9+7;
        for(int third = 3;third<=n;third++){
            int temp = ((long long)(third-1)*(first+second))%mod;
            first = second, second = temp;
        }
        return second;
    }
};