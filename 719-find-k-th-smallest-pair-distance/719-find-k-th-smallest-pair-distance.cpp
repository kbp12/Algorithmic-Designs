class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=1e6+1;
        while(l<=r){
            int m = l+(r-l)/2;
            int count = 0, i=0;
            for(int j=0;j<n;j++){
                if(nums[j]-nums[i]<=m){
                    count+=(j-i);
                }else{
                    while(i<n and nums[j]-nums[i]>m) i++;
                    count+=(j-i);
                }
            }
            if(count>=k){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return r+1;
    }
};