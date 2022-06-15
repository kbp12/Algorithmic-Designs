class Solution {
public:
    bool backtrack(int i, int n, int k, int a[], int total[], int sum){
        if(i==n){
            return true;
        }
        for(int j=0;j<k;j++){
            if(total[j]!=0){
                if(total[j]+a[i]<=sum){
                    total[j]+=a[i];
                    if(backtrack(i+1,n,k,a,total,sum)){
                        return true;
                    }
                    total[j]-=a[i];
                }
            }else{
                if(total[j]+a[i]<=sum){
                    total[j]+=a[i];
                    if(backtrack(i+1,n,k,a,total,sum)){
                        return true;
                    }
                    total[j]-=a[i];
                }
                break;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int a[n];
        for(int i=0;i<n;i++){
            a[i] = nums[i];
        }
        int sum = 0;
         if(k==1) return true;
         if(k>n) return false;
         for(int i=0;i<n;i++){
             sum+=a[i];
         }
         if(sum%k!=0) return false;
         sum = sum/k;
         int total[k];
         for(int i=0;i<k;i++) total[i] = 0;
         if(backtrack(0,n,k,a,total,sum)){
             return true;
         }
         return false;
    }
};