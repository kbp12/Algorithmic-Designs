class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0, i=0, curr = 0;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                curr++;
            }else{
                if(curr==i){
                    ans = curr;
                }else{
                    ans = max(ans,(curr+1)/2);
                }
                curr = 0;
            }
        }
        ans = max(ans,curr);
        return ans;
    }
};