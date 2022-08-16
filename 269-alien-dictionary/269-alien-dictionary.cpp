class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<int>adj[26];
        vector<int>indeg(26,0);
        int sz = words.size();
        set<int>s;
        vector<int>cnt(26,0);
        for(int i=0;i<sz;i++){
            for(auto ch:words[i]){
                s.insert(ch-'a');
            }
            int l1 = words[i].size();
            for(int j=0;j<i;j++){
                int l2 = words[j].size();
                int a=0,b=0;
                while(a<l1 and b<l2){
                    if(words[i][a]!=words[j][b]){
                        adj[words[i][a]-'a'].push_back(words[j][b]-'a');
                        indeg[words[j][b]-'a']++;
                        break;
                    }
                    a++; b++;
                }
                if(b==l1 and l1<l2) return "";
            }
        }
        
        queue<int>q;
        string ans = "";
        for(int i=0;i<26;i++){
            if(s.find(i)!=s.end() and indeg[i]==0){
                ans.push_back('a'+i);
                q.push(i);
                s.erase(i);
            }
        }
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                for(auto next:adj[f]){
                    indeg[next]--;
                    if(indeg[next]==0){
                        s.erase(next);
                        q.push(next);
                        ans.push_back('a'+next);
                    }
                }
            }
        }
        if(s.size()) return "";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};