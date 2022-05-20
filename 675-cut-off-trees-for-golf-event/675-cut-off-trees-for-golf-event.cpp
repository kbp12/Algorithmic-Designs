class Solution {
public:
    bool ispoint(int i, int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    
    int cutOffTree(vector<vector<int>>& f) {
        int m = f.size();
        int n = f[0].size();
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(f[i][j]>1){
                    v.push_back({f[i][j],{i,j}});
                }
            }
        }
        sort(v.begin(),v.end());
        int cx = 0, cy = 0;
        int ans = 0;
        for(int i=0;i<v.size();i++){
            int x = v[i].second.first, y = v[i].second.second;
            int count = 0;
            queue<pair<int,int>>q;
            q.push({cx,cy});
            bool found = false;
            vector<vector<bool>>visit(m,vector<bool>(n,false));
            visit[cx][cy] = true;
            while(!q.empty()){
                int s = q.size();
                for(int j=0;j<s;j++){
                    int a = q.front().first, b = q.front().second; q.pop();
                    if(a==x && b==y){
                        found = true;
                        break;
                    }
                    if(ispoint(a-1,b,m,n) && f[a-1][b]!=0 && visit[a-1][b]==false){
                        visit[a-1][b] = true;
                        q.push({a-1,b});
                    }
                    if(ispoint(a+1,b,m,n) && f[a+1][b]!=0 && visit[a+1][b]==false){
                        visit[a+1][b] = true;
                        q.push({a+1,b});
                    }
                    if(ispoint(a,b-1,m,n) && f[a][b-1]!=0 && visit[a][b-1]==false){
                        visit[a][b-1] = true;
                        q.push({a,b-1});
                    }
                    if(ispoint(a,b+1,m,n) && f[a][b+1]!=0 && visit[a][b+1]==false){
                        visit[a][b+1] = true;
                        q.push({a,b+1});
                    }
                }
                if(found) break;
                count++;
            }
            if(found==false) return -1;
            ans+= count;
            cx = x, cy = y;
        }
        return ans;
    }
};