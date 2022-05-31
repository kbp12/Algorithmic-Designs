class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        stack<int>st1,st2;
        int i=0;
        while(i<n){
            if(st1.size()==0 || nums[st1.top()]<nums[i]){
                st1.push(i); i++;
            }else{
                break;
            }
        }
        i = n-1;
        while(i>=0){
            if(st2.size()==0 || nums[st2.top()]>nums[i]){
                st2.push(i); i--;
            }else{
                break;
            }
        } 
        int a = st1.top(), b = st2.top();
        if(a>b) return true;
        else if(a==b-1){
            if(st1.size()==1 || st2.size()==1) return true;
            st1.pop(); st2.pop();
            int c = st1.top(), d = st2.top();
            if(nums[b]>nums[c]) return true;
            else if(nums[d]>nums[a]) return true;
            return false;
        }
        return false;
    }
};