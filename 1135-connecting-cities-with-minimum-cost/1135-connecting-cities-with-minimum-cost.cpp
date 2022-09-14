class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>g[n+1];
        for(auto c:connections){
            g[c[0]].push_back({c[1],c[2]});
            g[c[1]].push_back({c[0],c[2]});
        }
        vector<int>visited(n+1,false);
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        int cities = 0, ans =0;
        dist[1] = 0;
        while(cities<n and pq.size()){
            auto [f,s] = pq.top(); pq.pop();
            if(visited[s]) continue;
            visited[s] = true;
            ans+=f;
            for(auto next:g[s]){
                int city = next.first;
                int cost = next.second;
                if(visited[city]==false and dist[city]>cost){
                    dist[city] = cost;
                    pq.push({cost,city});
                }
            }
            cities++;
        }
        if(cities<n) return -1;
        return ans;
    }
};