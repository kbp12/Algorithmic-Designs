class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>umap;
        unordered_map<int,string>rever;
        int temp = 1;
        for(auto recipe:recipes){
            umap[recipe] = temp; 
            rever[temp] = recipe;
            temp++;
        }
        unordered_set<string>supply;
        for(auto sup:supplies) supply.insert(sup);
        int n = recipes.size();
        vector<int>indegree(n+1,0);
        vector<int>adj[n+1];
        for(int i=0;i<recipes.size();i++){
            int a = umap[recipes[i]];
            for(auto ing:ingredients[i]){
                if(supply.find(ing)==supply.end()){
                    int b = umap[ing];
                    adj[b].push_back(a);
                    indegree[a]++;
                }
            }
        }
        vector<string>ans;
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(rever[i]);
            }
        }
        while(q.size()){
            int f = q.front(); q.pop();
            for(auto next:adj[f]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                    ans.push_back(rever[next]);
                }
            }
        }
        return ans;
    }
};