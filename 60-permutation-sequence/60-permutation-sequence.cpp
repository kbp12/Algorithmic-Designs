class Solution {
public:
    vector<int>dp={1,1,2,6,24,120,720,5040,40320};
    string ans = "";
    void solve(vector<char>v,int n, int k){
        if(n==1){
            ans.push_back(v[0]);
            return;
        }
        int idx = 0;
        while(true){
            int a = dp[n-1];
            if(a>=k){
                ans.push_back(v[idx]);
                v.erase(find(v.begin(),v.end(),v[idx]));
                solve(v,n-1,k);
                return;
            }
            k= k-dp[n-1];
            idx++;
        }
        return;
    }
    
    string getPermutation(int n, int k) {
        vector<char>v;
        for(int i=1;i<=n;i++) v.push_back('0'+i);
        solve(v,n,k);
        return ans;
    }
};