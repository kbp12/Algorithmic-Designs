class Solution {
public:
    vector<vector<vector<int>>>dp;
    
    vector<int> recur(string s, int l, int r){
        bool ope = false;
        vector<int>res;
        for(int i=l+1;i<r;i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                ope = true;
                if(dp[l][i-1].size()==0){
                    dp[l][i-1] = recur(s,l,i-1);
                }
                if(dp[i+1][r].size()==0){
                    dp[i+1][r] = recur(s,i+1,r);
                }
                for(auto a:dp[l][i-1]){
                    for(auto b:dp[i+1][r]){
                        if(s[i]=='+') res.push_back(a+b);
                        else if(s[i]=='-') res.push_back(a-b);
                        else res.push_back(a*b);
                    }
                }
            }
        }
        if(ope){
            return res;
        }
        int ans = stoi(s.substr(l,r-l+1));
        return {ans};
    }
    
    vector<int> diffWaysToCompute(string s) {
        int n = s.length();
        dp = vector<vector<vector<int>>> (n,vector<vector<int>>(n));
        return recur(s,0,n-1);
    }
};