class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int ans1 = 0;
        int f = nums[0];
        int s = max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            int t = max(f+nums[i],s);
            f = s;
            s = t;
        }
        ans1 = s;
        f = nums[1]; 
        s = max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            int t = max(f+nums[i],s);
            f = s;
            s = t;
        }
        return max(ans1,s);
    }
};