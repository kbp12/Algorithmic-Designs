class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>presum(n+1,0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==1){
                presum[shifts[i][0]] += 1;
                presum[shifts[i][1]+1] -=1;
            }else{
                presum[shifts[i][0]] -=1;
                presum[shifts[i][1]+1] +=1;
            }
        }
        int p = 0;
        for(int i=0;i<n;i++){
            p+= presum[i];
            p = p%26;
            int temp = (s[i]-'a'+p)%26;
            if(temp<0){
                s[i] = 'a'+(26+temp);
            }else{
                s[i] = 'a'+temp;
            }
        }
        return s;
    }
};