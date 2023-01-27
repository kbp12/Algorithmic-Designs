class Solution {
public:
    bool intersect(vector<int>& a,vector<int>& b){
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j])  
                return true;
            if(a[i]<b[j])
                i++;
            else
                j++;
        }
        return false;   
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		if(S==T)
            return 0;
        int n=routes.size();
        vector<int> graph[n];
        for(auto route : routes){
            sort(route.begin(),route.end());
        }
        set<int> seen;
        set<int> target;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intersect(routes[i],routes[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(binary_search(routes[i].begin(), routes[i].end() , S)){
                seen.insert(i);
                q.push({i,0});
            }
            if(binary_search(routes[i].begin(), routes[i].end(), T)){
                target.insert(i);
            }
        }
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int node = p.first;
            int depth = p.second;
            if(target.find(node)!=target.end())
                return depth+1;
            for(int nei : graph[node]){
                if(seen.find(nei)==seen.end()){
                    seen.insert(nei);
                    q.push({nei,depth+1});
                }
            }
        } 
        return -1;
    }
};