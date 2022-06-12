class Solution {
public:
    int ans = INT_MAX;
    void solve(vector<int>cookies,int k, int i,int n, int c,vector<vector<int>>v){
        if(i==n){
            if(c==k){
                int res = 0;
                for(int j=0;j<k;j++){
                    int s = 0;
                    for(auto it:v[j]) s+=it;
                    res = max(res,s);
                }
                ans = min(ans,res);
            }
            return;
        }
        for(int j=0;j<k;j++){
            if(v[j].size()){
                v[j].push_back(cookies[i]);
                solve(cookies,k,i+1,n,c,v);
                v[j].pop_back();
            }else{
                v[j].push_back(cookies[i]);
                solve(cookies,k,i+1,n,c+1,v);
                break;
            }
        }
        return;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<vector<int>>v(k);
        solve(cookies,k,0,n,0,v);
        return ans;
    }
};