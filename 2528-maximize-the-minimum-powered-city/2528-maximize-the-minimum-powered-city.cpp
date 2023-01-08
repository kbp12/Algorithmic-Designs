class Solution {
public:
    long long maxPower(vector<int>& a, int r, int k) {
        #define int long long 
        int st=0; 
        int en=1e12;
        int ans=0; 
        int n=a.size(); 
        vector<int> dp(n+1); 
        vector<int> at(n); 
        for(int i=0;i<n;i++)dp[i+1]=dp[i]+a[i]; 
        for(int i=0;i<n;i++)
        {
            at[i]=dp[min(n,i+r+1)]-dp[max(0LL,i-r)]; 
        }
        auto check=[&](int d)
        {
            vector<int> add(n+1);
            int left=k; 
            for(int i=0;i<n;i++)
            {
                if(i)add[i]+=add[i-1]; 
                if(at[i]+add[i]>=d)continue; 
                int need=(d-at[i]-add[i]); 
                if(need>left)return false; 
                left-=need; 
                add[i]+=need; 
                if(i+2*r+1<n)add[i+2*r+1]-=need; 
            }
            return true; 
        };
            while(st<=en)
            {
                int mid=(st+en)>>1; 
                if(check(mid))ans=mid,st=mid+1; 
                else en=mid-1; 
            }
        return ans; 
        #undef int 
    }
};
