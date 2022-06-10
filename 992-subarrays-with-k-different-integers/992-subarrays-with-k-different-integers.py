class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        return self.withAtmostK(nums,k)-self.withAtmostK(nums,k-1)
    
    def withAtmostK(self,nums,k):
        i = 0; ans = 0;
        count = collections.Counter()
        for j in range(len(nums)):
            if(count[nums[j]]==0):
                k-=1
            count[nums[j]]+=1
            while(k<0):
                if(count[nums[i]]==1):
                    k+=1
                count[nums[i]]-=1
                i+=1
            ans+= j-i+1
        return ans