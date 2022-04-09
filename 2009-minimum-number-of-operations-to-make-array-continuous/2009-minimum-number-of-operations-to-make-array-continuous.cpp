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
        for(int i=0;i<m;i++){
            int j;
            auto it = upper_bound(nums.begin(),nums.end(),nums[i]+n-1);
            if(it != nums.end()){
                j = it - nums.begin();
                ans = min(ans,n-(j-i));
            }else{
                ans = min(ans,n-(m-i));
            }
            
        }
        return ans;
    }
};