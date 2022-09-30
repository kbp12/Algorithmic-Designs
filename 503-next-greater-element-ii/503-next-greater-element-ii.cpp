class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0], idx = 0;
        for(int i=1;i<n;i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                idx = i;
            }
        }
        vector<int>ans(n);
        ans[idx] = -1; 
        stack<int>mono;
        mono.push(nums[idx]);
        int c = 1;
        idx--;
        while(c<n){
            if(idx<0) idx = n-1;
            while(mono.size() and mono.top()<=nums[idx]) mono.pop();
            if(mono.size()) ans[idx] = mono.top();
            else ans[idx] = -1;
            mono.push(nums[idx]);
            idx--;
            c++;
        }
        return ans;
    }
};