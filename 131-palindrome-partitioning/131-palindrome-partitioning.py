class Solution:
    def partition(self, s: str) -> List[List[str]]:
        substring = []
        result = []
        def dfs(i):
            if i >= len(s):
                result.append(substring.copy())
                return 
            for j in range(i, len(s)):
                if self.check_palindrome(s, i, j):
                    substring.append(s[i:j+1])
                    dfs(j+1)
                    substring.pop()       
        dfs(0)
        return result 
     
    def check_palindrome(self, s, l, r):
        while l < r:
            if s[l] == s[r]:
                l += 1
                r -= 1
            else:
                return False
        return True 