class Solution {
public:
    long long sumScores(string s) {
        int n = s.length();
        int l=0,r=0,i=1;
        int arr[n];
        arr[0] = 0;
        while(i<n){
            if(i>r){
                l=i,r=i;
                while(r<n && s[r-l]==s[r]) r++;
                arr[i] = r-l;
                r--;
            }else{
                if(arr[i-l]+i<r){
                    arr[i] = arr[i-l];
                }else{
                    l=i;
                    while(r<n && s[r-l]==s[r])r++;
                    arr[i] = r-l;
                    r--;
                }
            }
            i++;
        }
        long long count =n;
        for(int i=1;i<n;i++) count+= arr[i];
        return count;
    }
};