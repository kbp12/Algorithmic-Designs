class Solution {
public:
    int s;
    int dp[4] = {0};
    int a[15];
    bool backtrack(int i, int n){
        if(i==n){
            return true;
        }
        for(int j=0;j<4;j++){
            if(dp[j]+a[i]<=s){
                dp[j]+=a[i];
                if(backtrack(i+1,n)){
                    return true;
                }
                dp[j]-=a[i];
            }
        }
        return false;
    } 
    
    bool makesquare(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++) a[i] = arr[i];
        s = 0;
        for(int i=0;i<n;i++){
            s+=a[i];
        }
        sort(a,a+n,greater<int>());
        if(s%4) return false;
        s = s/4;
        return backtrack(0,n);
    }
};