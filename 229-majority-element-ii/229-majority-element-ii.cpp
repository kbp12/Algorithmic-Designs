class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int a=0,b=1,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a) c1++;
            else if(nums[i]==b) c2++;
            else if(c1==0) a=nums[i], c1 = 1;
            else if(c2==0) b=nums[i], c2 = 1;
            else{
                c1--, c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==a) c1++;
            else if(nums[i]==b) c2++;
        }
        vector<int>ans;
        if(c1>n/3) ans.push_back(a);
        if(c2>n/3) ans.push_back(b);
        return ans;
    }
};