class KthLargest {
public:
    int x;
    vector<int>ans;
    KthLargest(int k, vector<int>& nums) {
        x = k;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=max(0,n-k);i<n;i++){
            ans.push_back(nums[i]);
        }
        return;
    }
    
    int add(int val) {
        if(ans.size()<x){
            ans.push_back(val);
            sort(ans.begin(),ans.end());
            return ans[0];
        }
        if(val<=ans[0]) return ans[0];
        int n = ans.size();
        if(n==1) ans[0] = max(ans[0],val);
        for(int i=1;i<n;i++){
            if(ans[i]<val){
                ans[i-1] = ans[i];
            }else{
                ans[i-1] = val;
                break;
            }
        }
        if(val>ans[n-1]) ans[n-1] = val;
        return ans[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */