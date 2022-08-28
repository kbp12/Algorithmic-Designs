class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<n;i++){
            int x=0,y=i;
            vector<int>t;
            while(x<m && y<n){
                t.push_back(mat[x][y]);
                x++; y++;
            }
            sort(t.begin(),t.end());
            x=0;y=i;
            int k =0;
            while(x<m && y<n){
                mat[x][y] = t[k];
                k++; x++; y++;
            }
        }
        for(int i=1;i<m;i++){
            int x = i,y=0;
            vector<int>t;
            while(x<m && y<n){
                t.push_back(mat[x][y]);
                x++; y++;
            }
            sort(t.begin(),t.end());
            x=i;y=0;
            int k =0;
            while(x<m && y<n){
                mat[x][y] = t[k];
                k++; x++; y++;
            }
        }
        return mat;
    }
};