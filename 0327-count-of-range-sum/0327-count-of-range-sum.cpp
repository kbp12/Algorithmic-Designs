class Solution {
public:
    int bs(long long temp[], double val, int r){
        int l = 0, m;
        while(l<=r){
            m = l+(r-l)/2;
            if(temp[m]<=val){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return l;
    }
    
    int divide(vector<int>& nums, int l, int r, int lower, int upper){
        if(l==r){       // base condition
            if(nums[l]>=lower && nums[l]<=upper) return 1;
            return 0;
        }
        int mid = l+(r-l)/2;
        int count = 0;
        count+=divide(nums,l,mid,lower,upper);
        count+=divide(nums,mid+1,r,lower,upper);
        long long temp[r-mid];
        long long sum = 0;
        for(int i=mid+1;i<=r;i++){
            sum+=nums[i];
            temp[i-mid-1] = sum;
        }
        sort(temp,temp+(r-mid));
        sum = 0;
        for(int i=mid;i>=l;i--){
            sum+=nums[i];
            count+=(bs(temp, upper-sum + 0.5,r-mid-1) - bs(temp,lower-sum - 0.5,r-mid-1));
        }
        return count;
    }
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        return divide(nums,0,n-1,lower,upper);
    }
};