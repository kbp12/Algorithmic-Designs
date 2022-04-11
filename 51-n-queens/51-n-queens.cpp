class Solution {
public:
    vector<vector<string>>ans;
    bool issafe(int r,int c, vector<string>& res){
        for(int i=0;i<res.size();i++){if(i!=r && res[i][c]=='Q') return false;}
        for(int i=0;i<res[0].size();i++){if(i!=c && res[r][i]=='Q') return false;}
        for(int i=r,j=c;i>=0 && j>=0;i--,j--){if(res[i][j]=='Q') return false;}
        for(int i=r,j=c;i>=0 && j<res[0].size();i--,j++){if(res[i][j]=='Q') return false;}
        return true;    
    }
    
    void backtrack(int row, int n, vector<string>& res){
        if(row==n){ans.push_back(res); return;}
        string temp = "";
        for(int i=0;i<n;i++) temp+= '.';
        res.push_back(temp);
        for(int i=0;i<n;i++){
            if(issafe(row,i,res)){
                res[row][i] = 'Q';
                backtrack(row+1,n,res);
                res[row][i] = '.';
            }
        }
        res.pop_back();
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>res;
        backtrack(0,n,res);
        return ans;
    }
};