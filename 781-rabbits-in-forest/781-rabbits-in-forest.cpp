class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int>cnt(1001,0);
        for(auto ans:answers){
            cnt[ans]++;
        }
        int total = 0;
        for(int i=0;i<1001;i++){
            if(cnt[i]){
                int a = i+1;
                int d = cnt[i]/a;
                if(cnt[i]%a) d++;
                total+=(d*a);
            }
        }
        return total;
    }
};