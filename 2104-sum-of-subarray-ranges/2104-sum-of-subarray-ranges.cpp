class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>ls(n),lb(n), rs(n), rb(n);
        stack<int>st1,st2;
        for(int i=0;i<n;i++){
            while(st1.size() and nums[st1.top()]>nums[i]) st1.pop();
            while(st2.size() and nums[st2.top()]<nums[i]) st2.pop();
            if(st1.size()) ls[i] = st1.top();
            else ls[i] = -1;
            if(st2.size()) lb[i] = st2.top();
            else lb[i] = -1;
            st1.push(i);
            st2.push(i);
        }
        stack<int>st3,st4;
        for(int i=n-1;i>=0;i--){
            while(st3.size() and nums[st3.top()]>=nums[i]) st3.pop();
            while(st4.size() and nums[st4.top()]<=nums[i]) st4.pop();
            if(st3.size()) rs[i] = st3.top();
            else rs[i] = n;
            if(st4.size()) rb[i] = st4.top();
            else rb[i] = n;
            st3.push(i);
            st4.push(i);
        }
        long long high = 0, low = 0;
        for(int i=0;i<n;i++){ 
            low+=((long long)nums[i]*(rs[i]-i)*(i-ls[i]));
            high+= ((long long)nums[i]*(rb[i]-i)*(i-lb[i]));
        }
        return high-low;
    }
};