class Solution {
public:
    
    int findlcm(int a,int b)
    {
        long long prod=1LL*a*b;
        int gcd=__gcd(a,b);
        prod/=gcd;
        if(prod<=2e9)
        {
            return prod;
        }
        else 
        {
            return 2e9+1;
        }
    }
    
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int l=1,r=2e9;
        int ans=r;
        int lcm=findlcm(divisor1,divisor2);
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int useless=mid/lcm;
            int a=mid/divisor1;
            int b=mid/divisor2;
            a-=useless;
            b-=useless;
            int cnt1=b;
            int cnt2=a;
            int rem=mid-(a+b+useless);
            if(cnt1<uniqueCnt1)
            {
                rem-=(uniqueCnt1-cnt1);
            }
            if(cnt2<uniqueCnt2)
            {
                rem-=(uniqueCnt2-cnt2);
            }
            if(rem>=0)
            {
                ans=mid;
                r=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        return ans;
    }
};