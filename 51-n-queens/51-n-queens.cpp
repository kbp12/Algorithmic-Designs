class Solution {
public:
    vector<vector<string>>ans;
    bool issafe(int i, int j,int n, vector<string>&v){
        for(int k=i-1;k>=0;k--){if(v[k][j]=='Q') return false;}
        for(int x=i-1,y=j-1;x>=0&&y>=0;x--,y--){if(v[x][y]=='Q')return false;}
        for(int x=i-1,y=j+1;x>=0&&y<n;x--,y++){if(v[x][y]=='Q') return false;}
        return true;
    }
    
    void backtrack(int idx,int n, vector<string>&v){
        if(idx==n){ans.push_back(v); return;}
        for(int i=0;i<n;i++){
            if(issafe(idx,i,n,v)){
                v[idx][i] = 'Q';
                backtrack(idx+1,n,v);
                v[idx][i] = '.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n;i++) s.push_back('.');
        vector<string>v;
        for(int i=0;i<n;i++) v.push_back(s);
        backtrack(0,n,v);
        return ans;
    }
};