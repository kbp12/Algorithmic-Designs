class Solution {
public:
    int closetTarget(vector<string>& w, string t, int si) {
        int n = w.size();
        int ans1 = -1, ans2 = -1;
        int cnt = 0;
        int sz = n+1;
        int j = si;
        while(sz--){
            if(w[j] ==  t){
                ans1 = cnt;
                break;
            }
            cnt++;
            j--;
            if(j==-1) j = n-1;
        }
        cnt = 0;
        j = si;
        sz=n+1;
        while(sz--){
            if(w[j]==t){
                ans2 = cnt;
                break;
            }
            cnt++;
            j++;
            if(j==n){
                j = 0;
            }
        }
        if(ans1 ==-1 and ans2==-1) return -1;
        int a = n+1;
        if(ans1!=-1) a = min(a , ans1);
        if(ans2!=-1) a = min(a , ans2);
        return a;
    }
};