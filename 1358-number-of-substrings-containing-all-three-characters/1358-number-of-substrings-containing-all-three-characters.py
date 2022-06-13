class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n=len(s);a=0;b=0;c=0;
        ans=0;i=0;
        for j in range(n):
            if(s[j]=='a'):
                a+=1
            elif(s[j]=='b'):
                b+=1
            else:
                c+=1
            while(a and b and c):
                ans+= n-j
                if(s[i]=='a'):
                    a-=1
                elif(s[i]=='b'):
                    b-=1
                else:
                    c-=1
                i+=1
        return ans