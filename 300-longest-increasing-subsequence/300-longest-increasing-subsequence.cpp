class Solution {
public:
    int bs(vector<int>& lis, int t){
        int i=0, j = lis.size()-1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(lis[m]<t){
                i = m+1;
            }else{
                j = m-1;
            }
        }
        return i;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(auto num:nums){
            int pos = bs(lis,num);
            if(pos==lis.size()){
                lis.push_back(num);
            }else{
                lis[pos] = num;
            }
        }
        return lis.size();
    }
};