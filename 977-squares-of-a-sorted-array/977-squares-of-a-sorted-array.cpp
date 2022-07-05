class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size()-1;
        int i=0,j=n;
        vector<int>ans(j+1);
        while(i<=j){
            if(abs(nums[i])>=abs(nums[j])){
                ans[j-i] = nums[i]*nums[i]; i++;
            }else{
                ans[j-i] = nums[j]*nums[j]; j--;
            }
        }
        return ans;
    }
};
