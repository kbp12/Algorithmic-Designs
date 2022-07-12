class Solution {
public:
    int s;
    vector<int>dp;
    int a[15];
    bool backtrack(int i, int n, int a[]){
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
    
    bool makesquare(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<int>());
        int n = arr.size();
        for(int i=0;i<n;i++) a[i] = arr[i];
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