class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        for(int i=1;i<=1000;i++){
            if(i>a or i>b) break;
            if(a%i==0 and b%i==0) ans++;
        }
        return ans;
    }
};