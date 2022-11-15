class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        int n = A.size();
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<(i+1);j++){
            A[i][j]+= min(A[i+1][j] , A[i+1][j+1]);
        }
    }
    return A[0][0];
    }
};