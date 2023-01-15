class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n,0)), temp(n+1,vector<int>(n+1,0));
        int a,b,c,d;
        for(auto q:queries){
            a = q[0], b = q[1], c = q[2], d = q[3]+1;
            for(int i=a;i<=c;i++){
                temp[i][b]+=1;
                temp[i][d]-=1;
            }
        }
        for(int i=0;i<n;i++){
            int c = 0;
            for(int j=0;j<n;j++){
                c+=temp[i][j];
                mat[i][j] = c;
            }
        }
        return mat;
    }
};