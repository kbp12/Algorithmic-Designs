class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int>left(n,0), right(n,0);
        if(s[0]=='R') left[0] = 1e5;
        for(int i=1;i<n;i++){
            if(s[i]=='R') left[i] = 1e5;
            if(s[i]=='.') left[i] = max(0,left[i-1]-1);
        }
        if(s[n-1]=='L') right[n-1] = -1e5;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='L') right[i] = -1e5;
            if(s[i]=='.') right[i] = min(0,right[i+1]+1);
        }
        for(int i=0;i<n;i++){
            if(left[i]+right[i]>0) s[i] = 'R';
            else if(left[i]+right[i]<0) s[i] = 'L';
            else s[i] = '.';
        }
        return s;
    }
};