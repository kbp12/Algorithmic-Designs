class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>counts(32,0);
        int c = 0;
        for(auto num:nums){
            int i = 0;
            if(num<0) c++;
            num = abs(num);
            while(num){
                counts[i]+=(num&1);
                num = num/2;
                i++;
            }
        }
        long long ans = 0;
        for(int i=0;i<32;i++){
            counts[i] = counts[i]%3;
            if(counts[i]){
                ans+= 1<<i;
            }
        }
        c = c%3;
        if(c) return ans*-1;
        return ans;
    }
};