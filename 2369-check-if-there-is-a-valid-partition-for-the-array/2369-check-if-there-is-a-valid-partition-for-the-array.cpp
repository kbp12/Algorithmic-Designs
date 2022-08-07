class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>l(n,false);
        vector<bool>r(n,false);
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
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                
            }else{
                if(i==n-2){
                    if(nums[i]==nums[i+1]){
                        r[i] = true;
                    }
                }else{
                    if(nums[i]==nums[i+1]){
                        r[i] = r[i] || r[i+2];
                    }
                    if(nums[i]==nums[i+1] and nums[i+1]==nums[i+2]){
                        if(i==n-3){
                            r[i] = true;
                        }else{
                            r[i] = r[i] || r[i+3];
                        }
                    }
                    if(nums[i]==nums[i+1]-1 and nums[i+1]==nums[i+2]-1){
                        if(i==n-3){
                            r[i] = true;
                        }else{
                            r[i] = r[i] || r[i+3];
                        }
                    }
                }
            }
        }
        
        if(l[n-1] or r[0])
            return true;
        for(int i=0;i<n-1;i++){
            if(l[i] and r[i+1]){
                return true;
            }
        }
        return false;
    }
};