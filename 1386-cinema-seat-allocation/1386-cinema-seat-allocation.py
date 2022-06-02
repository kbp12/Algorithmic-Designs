class Solution:
    def maxNumberOfFamilies(self, n: int, r: List[List[int]]) -> int:
        m = len(r)
        ans = 0
        prev = 0
        r.sort()
        c = 0
        for i in range(m):
            if(prev==r[i][0]):
                if(r[i-1][1]==1 and r[i][1]==10):
                    ans+=2
                elif(r[i-1][1]<=3 and r[i][1]>=8):
                    ans+=1
                elif(r[i-1][1]==1 and r[i][1]>=6):
                    ans+=1
                elif(r[i][1]==10 and r[i-1][1]<=5):
                    ans+=1
            else:
                c+=1
                if(prev):
                    if(r[i-1][1]==1):
                        ans+=2
                    elif(r[i-1][1]<=5):
                        ans+=1
                if(r[i][1]==10):
                    ans+=2
                elif(r[i][1]>=6):
                    ans+=1
                prev = r[i][0]
        if(r[m-1][1]==1):
            ans+=2
        elif(r[m-1][1]<=5):
            ans+=1
        c = n-c
        ans+= 2*c
        return ans
        