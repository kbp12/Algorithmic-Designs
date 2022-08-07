class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& r) {
        vector<int>adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool>visit(n,false);
        int c = 1;
        set<int>s;
        for(auto rr:r){
            s.insert(rr);
        }
        queue<int>q;
        q.push(0);
        visit[0] = true;
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int f =  q.front(); q.pop();
                for(auto ne:adj[f]){
                    if(visit[ne]==false and s.find(ne)==s.end()){
                        c++;
                        visit[ne] = true;
                        q.push(ne);
                    }
                }
            }
        }
        return c;
    }
};