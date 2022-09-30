class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>right(m);
        stack<int>mono;
        unordered_map<int,int>mpp;
        for(int i=m-1;i>=0;i--){
            while(mono.size() and mono.top()<nums2[i]) mono.pop();
            if(mono.size()) right[i] = mono.top();
            else right[i] = -1;
            mpp[nums2[i]] = i;
            mono.push(nums2[i]);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = right[mpp[nums1[i]]];
        }
        return ans;
    }
};