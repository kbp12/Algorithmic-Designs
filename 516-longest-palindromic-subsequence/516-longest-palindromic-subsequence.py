class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        s2 = s[::-1]
        dp = []
        for i in range(0,n+1):
            temp = []
            for j in range(0,n+1):
                temp.append(0)
            dp.append(temp)
        for i in range(1,n+1):
            for j in range(1,n+1):
                if s[i-1]==s2[j-1]:
                    dp[i][j] = 1+dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        return dp[n][n]
        