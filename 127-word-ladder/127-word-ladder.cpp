class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<string>q;
        q.push(beginWord);
        int len = 1;
        int n = beginWord.size();
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                string f = q.front(); q.pop();
                if(f==endWord) return len;
                for(int j=0;j<n;j++){
                    char ch = f[j];
                    for(int k=0;k<26;k++){
                        char c = 'a'+k;
                        f[j] = c;
                        if(s.find(f)!=s.end()){
                            q.push(f);
                            s.erase(f);
                        }
                    }
                    f[j] = ch;
                }
            }
            len++;
        }
        return 0;
    }
};