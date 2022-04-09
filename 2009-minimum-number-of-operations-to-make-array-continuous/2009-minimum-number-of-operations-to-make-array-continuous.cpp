class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int>nums;
        int k=0;
        while(k<n){
            if(nums.size() && nums[nums.size()-1]==arr[k]){
            }else{
                nums.push_back(arr[k]);
            }
            k++;
        }
        int m = nums.size();
        int ans = n;
        int i=0;
        int j = 0;
        while(i<m){
            while(j<m && nums[j]<nums[i]+n) j++;
            ans = min(ans,n-(j-i));
            i++;
        }
        return ans;
    }
};