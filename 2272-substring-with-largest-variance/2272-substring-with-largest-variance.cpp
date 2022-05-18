class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        int n = s.length();
        for(char i='a';i<='z';i++){
            for(char j='a';j<='z';j++){
                if(i==j) continue;
                int mini = 0, maxi = 0;
                bool found = false;
                for(int k=0;k<n;k++){
                    if(s[k]==i) maxi++;
                    else if(s[k]==j) mini++;
                    if(mini>0){
                        ans = max(ans,maxi-mini);
                    }else{
                        if(found){
                            ans = max(ans,maxi-1);
                        }
                    }
                    if(mini>maxi){
                        mini = 0; maxi = 0;
                        found = true;
                    }
                }
            }
        }
        return ans;
    }
};