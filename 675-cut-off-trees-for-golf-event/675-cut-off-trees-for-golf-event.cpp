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
        vector<int>vx = {-1,0,0,1};
        vector<int>vy = {0,1,-1,0};
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
                    for(int k=0;k<4;k++){
                        int x1 = a+vx[k], y1 = b+vy[k];
                        if(ispoint(x1,y1,m,n) && f[x1][y1]!=0 && visit[x1][y1]==false){
                            visit[x1][y1] = true;
                            q.push({x1,y1});
                        }
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