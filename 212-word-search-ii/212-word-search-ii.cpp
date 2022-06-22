class Solution {
public:
    struct trie{
        trie* child[26];
        bool end;
        trie(){
            for(int i=0;i<26;i++){
                child[i] = NULL;
            }
            end = false;
        }
    };
    
    unordered_set<string>ans;
    
    void dfs(vector<vector<char>>& board,int i, int j, int n,int m,string &temp,trie* root){
        if(i<0||j<0||i>=n||j>=m||board[i][j]=='.') return;
        char ch = board[i][j];
        if(root->child[ch-'a']==NULL) return;
        temp+=ch;
        root = root->child[ch-'a'];
        if(root->end) ans.insert(temp);
        board[i][j] = '.';
        dfs(board,i+1,j,n,m,temp,root);
        dfs(board,i-1,j,n,m,temp,root);
        dfs(board,i,j+1,n,m,temp,root);
        dfs(board,i,j-1,n,m,temp,root);
        board[i][j] = ch;
        temp.pop_back();
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie* root = new trie();
        for(string word:words){
            trie* cur = root;
            for(char ch:word){
                if(cur->child[ch-'a']==NULL){
                    trie* newnode = new trie();
                    cur->child[ch-'a'] = newnode;
                }
                cur = cur->child[ch-'a'];
            }
            cur->end = true;
        }
        
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string temp = "";
                dfs(board,i,j,n,m,temp,root);
            }
        }
        vector<string>res;
        for(auto it:ans) res.push_back(it);
        return res;
    }
};