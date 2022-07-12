class Solution {
public:
    int s;
    vector<int>dp;
    
    bool backtrack(int i, int n, vector<int>&a){
        if(i==n){
            return true;
        }
        for(int j=0;j<4;j++){
            if(dp[j]+a[i]<=s){
                dp[j]+=a[i];
                if(backtrack(i+1,n,a)){
                    return true;
                }
                dp[j]-=a[i];
            }
        }
        return false;
    } 
    
    bool makesquare(vector<int>& a) {
        sort(a.begin(),a.end(),greater<int>());
        int n = a.size();
        s = 0;
        for(int i=0;i<n;i++){
            s+=a[i];
        }
        if(s%4) return false;
        s = s/4;
        dp.assign(4,0);
        return backtrack(0,n,a);
    }
};