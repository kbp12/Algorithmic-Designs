class Solution {
public:
    long long n;
    unordered_map<long long,int>mpp;
    int dfs(vector<int>adj[] , int i){
        long long ans;
        int c = 1;
        if(adj[i].size()==2){
            long long a = dfs(adj,adj[i][0]);
            long long b = dfs(adj,adj[i][1]);
            ans = a*b;
            if(n-1-a-b) ans*=(n-1-a-b);
            c+=a+b;
        }else if(adj[i].size() == 1){
            int a = dfs(adj,adj[i][0]);
            ans = a;
            if(n-1-a) ans*=(n-1-a);
            c+=a;
        }else{
            ans = n-1;
        }
        mpp[ans]++;
        return c;
    }
    
    int countHighestScoreNodes(vector<int>& p) {
        this->n = p.size();
        vector<int>adj[n];
        for(int i=1;i<n;i++){
            adj[p[i]].push_back(i);
        }
        dfs(adj,0);
        long long ans = INT_MIN, cnt = 0;
        for(auto it:mpp){
            if(it.first>ans){
                cnt = it.second;
                ans = it.first;
            }
        }
        return cnt;
    }
};