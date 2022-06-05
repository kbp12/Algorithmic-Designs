class Solution:
    def totalFruit(self, f: List[int]) -> int:
        a=0 
        b=0 
        c_a=0 
        c_b=0
        ans = 0 
        l = 0
        for i in range(len(f)):
            if(f[i] == b):
                l+=1
                c_b+=1
            elif(f[i]==a):
                l+=1
                a = b
                c_a = c_b
                b = f[i]
                c_b = 1
            else:
                l = c_b+1
                a = b
                c_a = c_b
                c_b = 1
                b = f[i]
            ans = max(ans,l)
        return ans;