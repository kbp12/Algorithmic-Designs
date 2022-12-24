class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
        int n = forts.size();
        for(int i=0;i<n;i++){
            if(forts[i] == 1){
                int cnt = 0 , j = i-1;
                while(j>=0 and forts[j]==0){
                    cnt++;
                    j--;
                }
                if(j>=0 and forts[j]==-1){
                    ans = max(ans , cnt);
                }
                cnt = 0 , j = i+1;
                while(j<n and forts[j]==0){
                    cnt++;
                    j++;
                }
                if(j<n and forts[j]==-1){
                    ans = max(ans , cnt);
                }
            }
        }
        return ans;
    }
};