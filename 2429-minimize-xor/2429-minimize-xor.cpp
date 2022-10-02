class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c = 0;
        vector<int>v(32,0);
        int j = 0;
        while(num2){
            if(num2 & 1) {
                v[j] = 1;
                c++;
            }
            j++;
            num2 = num2/2;
        }
        j = 0;
        vector<int>v2(32,0);
        int n = num1;
        while(num1){
            if(num1 & 1) {
                v2[j] = 1;
            }
            j++;
            num1 = num1/2;
        }
        for(int i=31;i>=0;i--){
            if(v2[i]>0 and c>0){
                v2[i] = -1;
                c--;
            }
        }
        for(int i=0;i<31;i++){
            if(v2[i]==0 and c>0) {v2[i] = 1; c--;}
            else if(v2[i]==-1) v2[i] = 1;
            else v2[i] = 0;
        }
        int ans = 0;
        
        for(int i=0;i<32;i++){
            if(v2[i])
                ans+=pow(2,i);
        }
        return ans;
    }
};