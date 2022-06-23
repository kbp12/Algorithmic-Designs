class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        priority_queue<int>pq;
        int count = 0;
        for(int i=0;i<courses.size();i++){
            count+=courses[i][0];
            pq.push(courses[i][0]);
            while(count>courses[i][1]){
                count-=pq.top(); pq.pop();
            }
        }
        return pq.size();
    }
};