class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>l(n,false);
        for(int i=0;i<n;i++){
            if(i==0){
                
            }else{
                if(i==1){
                    if(nums[i]==nums[i-1]){
                        l[i] = true;
                    }
                }else{
                    if(nums[i]==nums[i-1]){
                        l[i] = l[i-2] || l[i];
                    }
                    if(nums[i]==nums[i-1] and nums[i-1]==nums[i-2]){
                        if(i==2){
                            l[i] = true;
                        }else{
                            l[i] = l[i-3] || l[i];
                        }
                    }
                    if(nums[i]==nums[i-1]+1 and nums[i-1]==nums[i-2]+1){
                        if(i==2){
                            l[i] = true;
                        }else{
                            l[i] = l[i-3] || l[i];
                        }
                    }
                }
            }
        }  
        return l[n-1]==true;
    }
};