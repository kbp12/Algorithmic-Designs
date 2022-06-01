class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<bool>visit(n,false);
        int chunks = 0;
        int m = 0;
        for(int i=0;i<n;i++){
            bool yes = true;
            visit[arr[i]] = true;
            m = max(m,arr[i]);
            for(int j=m;j>=0;j--){
                if(visit[j]==false){
                    yes = false;
                    break;
                }
            }
            if(yes){
                chunks++;
            }
        }
        return chunks;
    }
};