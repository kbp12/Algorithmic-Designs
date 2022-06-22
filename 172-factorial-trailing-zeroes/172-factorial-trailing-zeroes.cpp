class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int p = 1;
        while(true){
            int f = pow(5,p);
            int c = n/f; p++;
            if(c==0) return ans;
            ans+= c;
        }
        return ans;
    }
};