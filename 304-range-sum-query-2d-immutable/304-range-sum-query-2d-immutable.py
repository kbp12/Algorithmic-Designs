class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        m = len(matrix)
        n = len(matrix[0])
        self.sum=[[0] * (n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                self.sum[i][j] = matrix[i-1][j-1]+self.sum[i-1][j]+self.sum[i][j-1]-self.sum[i-1][j-1]

    def sumRegion(self, r1: int, c1: int, r2: int, c2: int) -> int:
        r2+=1
        c2+=1
        return self.sum[r2][c2]+self.sum[r1][c1]-self.sum[r2][c1]-self.sum[r1][c2]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)