class Solution {
public:
    int ans = 0;
    
    bool isPossible(int i, int j, int n,vector<string>& temp){
        for(int k=i-1;k>=0;k--){
            if(temp[k][j]=='Q') return false;
        }
        for(int x = i-1, y = j-1;x>=0 && y>=0; x--,y--){
            if(temp[x][y]=='Q') return false;
        }
        for(int x = i-1, y = j+1;x>=0 && y<n;x--,y++){
            if(temp[x][y]=='Q') return false;
        }
        return true;
    }
    
    void backtrack(int i, int n, vector<string>& temp){
        if(i==n){
            ans++; return;
        }
        for(int k=0;k<n;k++){
            if(isPossible(i,k,n,temp)){
                temp[i][k] = 'Q';
                backtrack(i+1,n,temp);
                temp[i][k] = '.';
            }
        }
        return;
    }
    
    int totalNQueens(int n) {
        vector<string>temp(n);
        string s="";
        for(int i=0;i<n;i++) s.push_back('.');
        for(int i=0;i<n;i++) temp[i] = s;
        backtrack(0,n,temp);
        return ans;
    }
};