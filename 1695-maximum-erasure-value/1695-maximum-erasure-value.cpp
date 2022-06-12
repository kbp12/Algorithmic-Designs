class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>uset;
        int maxsum = 0, sum = 0;
        for(int i=0,j=0;j<n;j++){
            if(uset.find(nums[j])==uset.end()){
                sum+=nums[j];
                uset.insert(nums[j]);
                maxsum = max(maxsum,sum);
            }else{
                while(i<=j && nums[i]!=nums[j]){
                    sum-=nums[i]; 
                    uset.erase(uset.find(nums[i]));
                    i++;
                }
                i++;
            }
        }
        return maxsum;
    }
};