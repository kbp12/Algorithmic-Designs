class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>uset;
        for(auto num:nums){
            for(int i=2;i<=(sqrt(num));i++){
                while(num%i == 0){
                    uset.insert(i);
                    num/=i;
                }
            }
            if(num>1) uset.insert(num);
        }
        return uset.size();
    }
};