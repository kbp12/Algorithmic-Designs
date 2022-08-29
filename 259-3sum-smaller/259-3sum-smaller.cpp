class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int l = j+1, r = n-1;
                int val = target-nums[i]-nums[j];
                while(l<=r){
                    int m = l+(r-l)/2;
                    if(nums[m]<val){
                        l = m+1;
                    }else{
                        r = m-1;
                    }
                }
                ans+=l-(j+1);
            }
        }
        return ans;
    }
};