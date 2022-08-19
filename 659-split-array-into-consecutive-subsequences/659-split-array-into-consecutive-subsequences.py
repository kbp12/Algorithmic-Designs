class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        to_be_placed = collections.Counter(nums);
        endingAt = collections.Counter();
        
        for num in nums:
            if not to_be_placed[num]:
                continue;
            if endingAt[num-1]>0:
                endingAt[num-1]-=1;
                endingAt[num]+=1;
            elif to_be_placed[num+1]>0 and to_be_placed[num+2]>0:
                to_be_placed[num+1]-=1;
                to_be_placed[num+2]-=1;
                endingAt[num+2]+=1;
            else:
                return False;
            to_be_placed[num]-=1;
        return True;