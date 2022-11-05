class Solution {
public:
    struct trie{
        trie* child[26];
        bool end;
        trie(){
            for(int i=0;i<26;i++){
                child[i] = nullptr;
            }
            end = false;
        }
    };
    
    int n,m;
    unordered_set<string>uset;
    
    void dfs(int i, int j, vector<vector<char>>& board, trie* temp, string & str){
        if(i<0 or j<0 or i>=n or j>=m or board[i][j] == '#') return;
        char ch = board[i][j];
        if(temp->child[ch-'a'] == nullptr) return;
        
        str.push_back(ch);
        temp = temp->child[ch-'a'];
        if(temp->end) uset.insert(str);
        board[i][j] = '#';
        
        dfs(i+1,j,board,temp,str);
        dfs(i-1,j,board,temp,str);
        dfs(i,j+1,board,temp,str);
        dfs(i,j-1,board,temp,str);
        
        board[i][j] = ch;
        str.pop_back();
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie* root = new trie();
        for(auto word:words){
            trie* temp = root;
            for(auto ch:word){
                if(temp->child[ch-'a'] == nullptr){
                    trie* temp2 = new trie();
                    temp->child[ch-'a'] = temp2;
                }
                temp = temp->child[ch-'a'];
            }
            temp->end = true;
        }
        this->n = board.size();
        this->m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string str = "";
                dfs(i,j,board,root , str);
            }
        }
        vector<string>ans;
        for(auto it:uset){
            ans.push_back(it);
        }
        return ans;
    }
};