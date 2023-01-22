class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>v;
         int ans = 0;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        reverse(v.begin() , v.end());
        for(int i=0;i<v.size();i++){
            if(i%2){
                ans-=v[i];
            }else{
                ans+=v[i];
            }
        }
        return ans;
    }
};