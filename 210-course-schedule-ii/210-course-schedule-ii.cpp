class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>>g(numCourses);
        vector<int>indeg(numCourses,0);
        for(auto p:prereq){
            g[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                ans.push_back(i);
                q.push(i);
            }
        }
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                for(auto adj:g[f]){
                    indeg[adj]--;
                    if(indeg[adj]==0){
                        q.push(adj);
                        ans.push_back(adj);
                    }
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};