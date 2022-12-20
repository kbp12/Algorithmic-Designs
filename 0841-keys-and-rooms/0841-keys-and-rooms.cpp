class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visit(n,false);
        visit[0] = true;
        queue<int>q; q.push(0);
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                int f = q.front(); q.pop();
                for(auto next:rooms[f]){
                    if(visit[next]==false){
                        visit[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visit[i]==false) return false;
        }
        return true;
    }
};