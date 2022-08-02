class Solution {
public:
    int gcd(int a,int b){
        if(b>a) swap(a,b);
        return b==0?a:gcd(b,a%b);
    }
    
    bool canMeasureWater(int j1, int j2, int t) {
        if(j1==t or j2==t or j1+j2==t) return true;
        if(t>j1+j2) return false;
        int gcdd = gcd(j1,j2);
        return t%gcdd==0;
    }
};