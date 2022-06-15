class Solution {
public:
    int balancedString(string s) {
        vector<int>counts(4,0);
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='Q') counts[0]++;
            else if(s[i]=='W') counts[1]++;
            else if(s[i]=='E') counts[2]++;
            else counts[3]++;
        }
        int c = n/4;
        if(counts[0]==c && counts[1]==c && counts[2]==c && counts[3]==c) return 0;
        int ans = INT_MAX;
        
        for(int i=0,j=0;j<n;j++){
            if(s[j]=='Q') counts[0]--;
            else if(s[j]=='W') counts[1]--;
            else if(s[j]=='E') counts[2]--;
            else counts[3]--;
            while(i<=j){
                if(s[i]=='Q'){
                    if(counts[0]<c){counts[0]++; i++;}
                    else {break;}
                }else if(s[i]=='W'){
                    if(counts[1]<c){counts[1]++; i++;}
                    else{ break;}
                }else if(s[i]=='E'){
                    if(counts[2]<c){counts[2]++; i++;}
                    else{break;}
                }else{
                    if(counts[3]<c){counts[3]++; i++;}
                    else{break;}
                }
            }
            if(counts[0]<=c && counts[1]<=c && counts[2]<=c && counts[3]<=c)
                ans = min(ans,j-i+1);
        }
        return ans;
    }
};