class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        cnt = [0 for _ in range(1001)]
        for ans in answers:
            cnt[ans]+=1
        total = 0
        for i in range(0,1001):
            if(cnt[i]>0):
                a = i+1;
                d = cnt[i]//a;
                if(cnt[i]%a):
                    d+=1;
                total+=d*a;
        return total