class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        ans = [i for i in range(n)]
        dp = [[False]*(n) for _ in range(n)]
        for i in range(n):
            ans[i] = i
            for j in range(i,-1,-1):
                if(s[i]==s[j] and (i-j<2 or dp[j+1][i-1])):
                    dp[j][i] = True
                    if(j==0):
                        ans[i] = 0
                    else:
                        ans[i] = min(ans[i],1+ans[j-1])
        return ans[n-1]
        
        