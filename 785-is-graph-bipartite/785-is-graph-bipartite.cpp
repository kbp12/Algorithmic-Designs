class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visit(n); 
        queue<int> q;    
	
        for(int i = 0; i < n; i++){
            if (visit[i]) continue; 
            visit[i] = 1;
            q.push(i);
            while(!q.empty()){
                int curr = q.front(); q.pop();
                for (int neigh : graph[curr]) 
		        {
                    if (!visit[neigh]){ 
                        visit[neigh] = -visit[curr]; 
                        q.push(neigh); 
                    }else if (visit[neigh] == visit[curr]){ 
                        return false;
                    }
                }        
            }
        }
    return true;
    }
};