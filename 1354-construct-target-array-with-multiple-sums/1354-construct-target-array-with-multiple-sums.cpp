class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        int n = target.size();
        priority_queue<long long>pq;
        for(int i=0;i<n;i++){
            sum+=target[i];
            pq.push(target[i]);
        }
        while(pq.size()){
            long long a = pq.top(); pq.pop();
            if(a==1) return true;
            sum-= a;
            if(a==1 || sum==1) return true;
            if(a<sum || sum<=0 || a%sum==0) return false;
            a = a%sum;
            sum+=a;
            pq.push(a);
        }
        return true;
    }
};