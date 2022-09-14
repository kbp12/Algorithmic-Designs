class NumMatrix {
public:
    vector<vector<int>>grid;
    NumMatrix(vector<vector<int>>& matrix) {
        grid = matrix;
    }
    
    void update(int row, int col, int val) {
        grid[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int r=row1;r<=row2;r++){
            for(int c=col1;c<=col2;c++){
                sum=sum+grid[r][c];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */