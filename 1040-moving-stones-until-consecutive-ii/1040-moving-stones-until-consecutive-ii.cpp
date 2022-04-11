class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        int mini = n-1,i = 0, j = 0;
        if(stones[n-1]-stones[0]==n-1)
            mini=0;
        else if((stones[n-2]-stones[0]==n-2 || stones[n-1]-stones[1]==n-2)){
            mini = 2;
            if(stones[1]-stones[0]==2 || stones[n-1]-stones[n-2]==2) mini=1;   
        }else{
            while(i<n){
                if(stones[j]-stones[i]<=n-1){
                    while(j<n && stones[j]-stones[i]<=n-1) 
                        j++;
                    mini = min(mini,n-(j-i));
                }
                i++;
            }
        }
        //cout<<mini<<endl;
        int maxi = 0;
        for(int i=2;i<n-1;i++){
            maxi+= max(0,stones[i]-stones[i-1]-1);
        }
        maxi+= max(0,max(stones[1]-stones[0]-1,stones[n-1]-stones[n-2]-1));
        //cout<<maxi<<endl;
        return{mini,maxi};
    }
};