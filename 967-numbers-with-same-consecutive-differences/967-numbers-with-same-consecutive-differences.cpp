class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int>q;
        for(int i=1;i<=9;i++){
            q.push(i);
        }
        n--;
        while(q.size() and n){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int f = q.front(); q.pop();
                int l = f%10;
                int a = l-k, b = l+k;
                if(a>=0){
                    a = f*10+a;
                    q.push(a);
                }
                if(b<10 and k>0){
                    b = f*10+b;
                    q.push(b);
                }
            }
            n--;
        }
        vector<int>ans;
        while(q.size()){
            ans.push_back(q.front()); q.pop();
        }
        return ans;
    }
};