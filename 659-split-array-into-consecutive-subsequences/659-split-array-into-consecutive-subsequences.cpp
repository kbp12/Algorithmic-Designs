class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        map<int,priority_queue<int,vector<int>,greater<int>>>mpp;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i]-1)!=mpp.end()){
                int a = mpp[nums[i]-1].top();
                mpp[nums[i]-1].pop();
                if(mpp[nums[i]-1].size()==0){
                    mpp.erase(nums[i]-1);
                }
                mpp[nums[i]].push(a+1);
            }else{
                mpp[nums[i]].push(1);
            }
        }
        for(auto it:mpp){
            if(it.second.size() and it.second.top()<3) return false;
        }
        return true;
    }
};