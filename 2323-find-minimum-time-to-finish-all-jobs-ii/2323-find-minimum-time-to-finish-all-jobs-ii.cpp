class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        int ans = 0;
        for(int i=0;i<jobs.size();i++){
            int temp = jobs[i]/workers[i];
            if(jobs[i]%workers[i]) temp++;
            ans = max(ans,temp);
        }
        return ans;
    }
};