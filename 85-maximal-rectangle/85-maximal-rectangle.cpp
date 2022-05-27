class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = matrix[i][j]-'0';
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            stack<int>s,t;
            int a = 0;
            vector<int>l(n),r(n);
            if(i!=0){
                for(int j=0;j<n;j++){
                    if(mat[i][j])
                        mat[i][j]+=mat[i-1][j];
                }
            }
            
            for(int j=0;j<n;j++){
                while(s.size() && mat[i][s.top()]>=mat[i][j]){
                    s.pop();
                }
                if(s.size()){
                    l[j] = s.top();
                }else{
                    l[j] = -1;
                }
                s.push(j);
                while(t.size() && mat[i][t.top()]>=mat[i][n-1-j]){
                    t.pop();
                }
                if(t.size()){
                    r[n-1-j] = t.top();
                }else{
                    r[n-1-j] = n;
                }
                t.push(n-1-j);
            }
            
            for(int j=0;j<n;j++){
                a = max(a,mat[i][j]*(r[j]-l[j]-1));
            }
            ans = max(ans,a);
        }
        return ans;
    }
};