class Solution {
public:
    vector<vector<int>>ans;
    vector<int>v;
    void find(int idx, int sum, int k, int n){
    if(sum==n && k==0){
        ans.push_back(v);
        return;
    }
    if(sum>n) return;
    for(int i=idx;i<=9;i++){ 
        v.push_back(i);
        find(i+1,sum+i,k-1,n); 
        v.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum3(int k, int n) {
        find(1,0,k,n);
        return ans;
    }
};