class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        for(int r=0;r<n;r++){
            int i = r , j = 0;
            while(i<n and j<m){
                if(matrix[i][j] != matrix[r][0]) return false;
                i++; j++;
            }
        }
        for(int c = 1; c<m;c++){
            int i = 0, j = c;
            while(i<n and j<m){
                if(matrix[i][j] != matrix[0][c]) return false;
                i++; j++;
            }
        }
        return true;
    }
};