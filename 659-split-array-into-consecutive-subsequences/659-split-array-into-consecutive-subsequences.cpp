class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>endingAt, to_be_placed;
        for(auto num:nums){
            to_be_placed[num]++;
        }
        for(auto num:nums){
            if(to_be_placed[num]==0){
                continue;
            }
            if(endingAt[num-1]>0){
                endingAt[num-1]--;
                endingAt[num]++;
            }else if(to_be_placed[num+1]>0 and to_be_placed[num+2]>0){
                to_be_placed[num+1]--;
                to_be_placed[num+2]--;
                endingAt[num+2]++;
            }else{
                return false;
            }
            to_be_placed[num]--;
        }
        return true;
    }
};