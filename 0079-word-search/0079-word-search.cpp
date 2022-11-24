class Solution {
public:
    bool dfs(vector<vector<char>>& board,int i,int j,int n,int m,string &word, int k){
        if (k==word.length()) return true;
        if (i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[k]) return false;
        char c = board[i][j];
        board[i][j] = '*';
        bool ans = dfs(board,i-1,j,n,m,word,k+1)||dfs(board,i+1,j,n,m,word,k+1)||dfs(board,i,j-1,n,m,word,k+1)||dfs(board,i,j+1,n,m,word,k+1);
        board[i][j] = c;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board,string word){
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){ 
            for (int j=0;j<m;j++){
                if (dfs(board,i,j,n,m,word,0))
                    return true;
            }
        }
        return false;
    }
};