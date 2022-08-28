class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int max_idx = 0;
        int maxi = 0;
        int steps = 0;
        for(int i=0;i<n;i++){
            if(max_idx>=n-1) return steps;
            maxi = max(maxi,i+nums[i]);
            if(max_idx==i){
                steps++;
                max_idx = maxi;
            }
        }
        return steps;
    }
};