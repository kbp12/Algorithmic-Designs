class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        vector<int>pos(1e6+1,1);
        pos[1] = 0;
        for(long long i=2;i<=1e6;i++){
            for(long long j=i*i;j<=1e6;j+=i){
                pos[j] = 0;
            }
        }
        for(int i=left;i<=right;i++){
            if(pos[i]) ans.push_back(i);
        }
        int diff = 1e6,a=-1,b=-1;
        for(int i=1;i<ans.size();i++){
            if(ans[i]-ans[i-1] < diff){
                a = ans[i-1];
                b = ans[i];
                diff = ans[i]-ans[i-1];
            }
        }
        return {a,b};
    }
};