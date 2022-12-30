class Solution {
public:
    vector<vector<int>>ans;
    void bfs(vector<vector<int>>& graph, vector<int>& temp, int it, int n){
        if(it==n-1){ ans.push_back(temp); return;}
        int m = graph[it].size();
        for(int i=0;i<m;i++){
            temp.push_back(graph[it][i]);
            bfs(graph,temp,graph[it][i],n);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int>temp;  temp.push_back(0);
        bfs(graph,temp,0,n);
        return ans;
    }
};