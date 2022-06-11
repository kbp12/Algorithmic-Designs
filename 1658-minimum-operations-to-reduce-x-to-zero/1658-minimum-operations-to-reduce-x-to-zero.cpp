class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int>left,right;
        int leftSum = 0, rightSum = 0;
        for(int i=0;i<n;i++){
            leftSum+=nums[i];
            rightSum+=nums[n-1-i];
            left[leftSum]=i+1;
            right[rightSum]=i+1;
        }
        int ans1=INT_MAX, ans2=INT_MAX;
        int sum = 0;
        if(right.find(x)!=right.end()) ans1 = right[x];
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(right.find(x-sum)!=right.end() && (i+1+right[x-sum]<=n)){
                ans1 = min(ans1,i+1+right[x-sum]);
            }
        }
        sum = 0;
        if(left.find(x)!=left.end()) ans2 = left[x];
        for(int i=0;i<n;i++){
            sum+=nums[n-1-i];
            if(left.find(x-sum)!=left.end() && (i+1+left[x-sum]<=n)){
                ans2 = min(ans2,i+1+left[x-sum]);
            }
        }
        if(ans1==INT_MAX && ans2==INT_MAX) return -1;
        return min(ans1,ans2);
    }
};