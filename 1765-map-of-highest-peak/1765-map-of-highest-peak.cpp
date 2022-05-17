class Solution {
public:
    bool ispoint(int i,int j, int m, int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int m = w.size();
        int n = w[0].size();
        vector<vector<int>>h(m,vector<int>(n,0));
        vector<vector<bool>>visit(m,vector<bool>(n,true));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(w[i][j]){
                    q.push({i,j});
                    visit[i][j] = false;
                }
            }
        }
        int ans = 1;
        vector<int>x = {-1,0,0,1};
        vector<int>y = {0,-1,1,0};
        while(!q.empty()){
            int s = q.size();
            for(int it=0;it<s;it++){
                int a = q.front().first, b = q.front().second; q.pop();
                for(int k=0;k<4;k++){
                    int i = a+x[k], j = b+y[k];
                    if(ispoint(i,j,m,n) && visit[i][j]){
                        h[i][j] = ans; 
                        visit[i][j] = false;
                        q.push({i,j});
                    }
                }
            }
            ans++;
        }
        return h;
    }
};