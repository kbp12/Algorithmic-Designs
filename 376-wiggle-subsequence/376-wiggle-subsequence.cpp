class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int c = 1;
        int ispos = 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }else{
                int a = nums[i]-nums[i-1];
                if(ispos == 0){
                    ispos = a;
                    c++;
                }else if(ispos<0 && a>0){
                    ispos = a;
                    c++;
                }else if(ispos>0 && a<0){
                    ispos = a;
                    c++;
                }
            }
        }
        return c;
    }
};