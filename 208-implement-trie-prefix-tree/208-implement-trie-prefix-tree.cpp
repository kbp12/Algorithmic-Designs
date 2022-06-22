class Trie {
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
    
    trie* root;
    Trie() {
        root = new trie();
    }
    
    void insert(string word){
        trie *cur = root;
        for(char ch:word){
            if(cur->child[ch-'a']==NULL){
                trie *newnode = new trie();
                cur->child[ch-'a'] = newnode;
            }
            cur = cur->child[ch-'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        trie * cur = root;
        for(char ch:word){
            if(cur->child[ch-'a']==NULL) return false;
            cur = cur->child[ch-'a'];
        }
        if(cur->end) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trie * cur = root;
        for(char ch:prefix){
            if(cur->child[ch-'a']==NULL) return false;
            cur = cur->child[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */