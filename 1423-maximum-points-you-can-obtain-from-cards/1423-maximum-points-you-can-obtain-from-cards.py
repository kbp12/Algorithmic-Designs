class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        left = [0] *(k+1)
        right = [0] *(k+1)
        for i in range(1,k+1):
            left[i] = left[i-1] + cardPoints[i-1]
            right[k-i] = right[k+1-i] + cardPoints[n-i]
        ans = 0
        for i in range(k+1):
            ans = max(ans,left[i]+right[i])
        return ans