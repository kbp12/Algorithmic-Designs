class Solution:
    def countVowels(self, w: str) -> int:
        n = len(w)
        ans = 0
        for i in range(n):
            if(w[i]=='a' or w[i]=='e' or w[i]=='i' or w[i]=='o' or w[i]=='u'):
                ans+= (n-i)*(i+1)
        return ans