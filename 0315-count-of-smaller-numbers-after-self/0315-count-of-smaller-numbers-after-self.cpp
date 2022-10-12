class Solution {
public:
    int sumbit(vector<int>& bitree, int i){
        i++;
        int sum = 0;
        for(;i>0;i-=(i & (-i))){
            sum+=bitree[i];
        }
        return sum;
    }
    
    void updatebit(vector<int>& bitree, int i){
        i++;
        for(;i<=2e4+8;i+=(i & (-i))){
            bitree[i]+=1;
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>bitree(2e4+10,0);
        int toadd = 1e4+2;
        for(int i=n-1;i>=0;i--){
            ans[i] = sumbit(bitree,nums[i]+toadd-1);
            updatebit(bitree,nums[i]+toadd);
        }
        return ans;
    }
};