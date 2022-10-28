class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size() , ans = 0;
        if(hours[0] > 8) hours[0] = 1;
        else hours[0] = -1;
        for(int i=1;i<n;i++){
            if(hours[i] > 8){
                hours[i] = hours[i-1] + 1;
            }else{
                hours[i] = hours[i-1] - 1;
            }
        }
        vector<int>idx(20005,-1);
        for(int i=0;i<n;i++){
            int s = hours[i];
            if(s>0){
                ans = i+1;
            }
            s+=10000;
            if(idx[s-1] != -1){
                ans = max( ans , i - idx[s-1] );
            }
            if(idx[s] == -1){
                idx[s] = i;
            }
        }
        return ans;
    }
};