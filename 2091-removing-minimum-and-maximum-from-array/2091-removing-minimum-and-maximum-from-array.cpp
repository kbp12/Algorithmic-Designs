class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(); if(n==1) return 1;
        int minidx = 1, maxidx = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[maxidx-1]){
                maxidx = i+1;
            }
            if(nums[i]<nums[minidx-1]){
                minidx =i+1;
            }
        }
        return min(max(minidx,maxidx),min((min(minidx,maxidx)+n+1-max(minidx,maxidx)),n+1-min(minidx,maxidx)));
    }
};