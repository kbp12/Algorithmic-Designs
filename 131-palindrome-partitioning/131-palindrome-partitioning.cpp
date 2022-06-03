class Solution {
public:
    vector<vector<string>>ans;
    bool ispalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]==s[j]){
                i++; j--;
            }else 
                return false;
        }
        return true;
    }
    
    void solve(int i, int n, string s,vector<string> temp){
        if(i==n+1){
            ans.push_back(temp);
            return;
        }
        if(i==n){
            temp.push_back(s.substr(i,1));
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<=n;j++){
            if(ispalindrome(i,j,s)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,n,s,temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string>temp;
        solve(0,n-1,s,temp);
        return ans;
    }
};