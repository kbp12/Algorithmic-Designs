class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        for(auto task:tasks){
            v[task-'A']++;
        }
        sort(v.begin(),v.end());
        int val = v[25];
        int cnt = 1;
        int i = 24;
        while(i>=0){
            if(v[i]==val){
                cnt++;
            }else{
                break;
            }
            i--;
        }
        int total = tasks.size();
        return max(total,(v[25]-1)*n+v[25]+cnt-1);
    }
};