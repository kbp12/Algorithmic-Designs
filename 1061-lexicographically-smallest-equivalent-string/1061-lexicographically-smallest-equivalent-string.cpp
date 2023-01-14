class Solution {
public:
    char dfs(int node,vector<set<int>> &adj,int parent,set<int>&sett){
        if(sett.find(node) != sett.end()) return node+'a';
        sett.insert(node);
        int smallest=node,child_smallest;
        for(auto it:adj[node]){
           if(it==parent) continue;
           child_smallest=dfs(it,adj,node,sett)-'a';
           smallest=min(smallest,child_smallest);
        }

        return smallest+'a';
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<int>> adj(26,set<int>());
        for(int i=0;i<s1.size();i++){
            adj[s1[i]-'a'].insert(s2[i]-'a');
            adj[s2[i]-'a'].insert(s1[i]-'a');
        }
         
        string ans="";
        for(auto ch:baseStr){
            set<int>sett;
            ans+=dfs(ch-'a',adj,-1,sett);
        }

        return ans;
    }
};