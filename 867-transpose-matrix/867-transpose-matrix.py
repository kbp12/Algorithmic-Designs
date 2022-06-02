class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        transpose = []
        for i in range(0,n):
            temp = []
            for j in range(0,m):
                temp.append(matrix[j][i])
            transpose.append(temp)
        return transpose
        