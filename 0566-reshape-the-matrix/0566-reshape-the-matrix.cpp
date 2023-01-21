class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(n*m != r*c) return mat;
        vector<vector<int>>mat2(r,vector<int>(c));
        int x=0,y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat2[x][y] = mat[i][j];
                y++;
                if(y==c){
                    x++, y=0;
                }
            }
        }
        return mat2;
    }
};