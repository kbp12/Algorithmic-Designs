class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long long closesum = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];   
                if(sum==target)
                    return sum;
                if(abs(target-closesum)>abs(target-sum))
                    closesum=sum;
                if(sum>target)
                    r--;
                if(sum<target)
                    l++;
            }
        }
        return closesum;
    }
};