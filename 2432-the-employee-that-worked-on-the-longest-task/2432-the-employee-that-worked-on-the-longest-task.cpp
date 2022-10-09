class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int longest_time = 0, id = -1, prev_leave = 0;
        int m = logs.size();
        for(int i=0;i<m;i++){
            int time = logs[i][1] - prev_leave;
            if(time>longest_time){
                id = logs[i][0], longest_time = time;
            }else if(time == longest_time) id = min(id, logs[i][0]);
            prev_leave = logs[i][1];
        }
        return id;
    }
};