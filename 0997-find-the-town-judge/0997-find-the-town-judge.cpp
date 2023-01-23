class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int l = trust.size();
        int istrustedby[n];
        int dotrusts[n];
        for(int i=0;i<n;i++){
            istrustedby[i] = 0;
            dotrusts[i] = false;
        }
        for(int i=0;i<l;i++){
            dotrusts[trust[i][0]-1] = true;
            istrustedby[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++){
            if(dotrusts[i]==false && istrustedby[i]==n-1)
                return i+1;
        }
        return -1;
    }
};