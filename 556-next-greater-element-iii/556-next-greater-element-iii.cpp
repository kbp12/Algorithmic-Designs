class Solution {
public:
    int nextGreaterElement(int num) {
        string nums = to_string(num);
        string temp = nums;
        int n = nums.size();
        int i=n-1;
        while(i>0){
            if(nums[i-1]<nums[i]){
                int k = i-1;
                while(i<n-1 && nums[i+1]>nums[k])
                    i++;
                swap(nums[i],nums[k]);
                i = k+1; k = n-1;
                while(i<k){
                    swap(nums[i],nums[k]);
                    i++;k--;
                }
                break;
            }else{
                i--;
            }
        }
        if(temp==nums) return -1;
        long long t = stol(nums,nullptr,10);
        if(t>INT_MAX) return -1;
        return t;
    }
};