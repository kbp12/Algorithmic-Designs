class Solution {
public:
    int ans = INT_MAX;
    void PartitionSub(int arr[], int i,int N, int K, int nos,vector<vector<int> >& v)
{
    if (i >= N) {
        if (nos == K) {
            int maxsum = 0;
            for (int x = 0; x < v.size(); x++) {
                int sum = 0;
                for (int y = 0; y < v[x].size(); y++) {
                    sum+=v[x][y];
                    
                }
                maxsum = max(maxsum,sum);
            }
            ans= min(ans,maxsum);
        }
 
        return;
    }
 
    for (int j = 0; j < K; j++) {
 
        if (v[j].size() > 0) {
            v[j].push_back(arr[i]);
 
            PartitionSub(arr, i + 1, N, K, nos, v);

            v[j].pop_back();
        }
        else {
 
            v[j].push_back(arr[i]);
            PartitionSub(arr, i + 1, N, K, nos + 1, v);
            v[j].pop_back();
            break;
        }
    }
}
 
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int arr[n];
        for(int i=0;i<n;i++) arr[i] = cookies[i];
        vector<vector<int>>v(k);
        PartitionSub(arr,0,n,k,0,v);
        return ans;
    }
};