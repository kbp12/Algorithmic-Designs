class Solution {
public:
    vector<int> recur(string s, int l, int r){
        bool ope = false;
        vector<int>res;
        for(int i=l+1;i<r;i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                ope = true;
                for(auto a:recur(s,l,i-1)){
                    for(auto b:recur(s,i+1,r)){
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
        return recur(s,0,n-1);
    }
};