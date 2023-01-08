class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        
        priority_queue<pair<int,int>> pq_left,wait_left,pq_right,wait_right;
        
        for(int i=0;i<k;i++){
            pq_left.push({time[i][0]+time[i][2],i});
        }
        
        int ans=0;
        
        while(n>0||!pq_right.empty()||!wait_right.empty()){
              
            if(!pq_right.empty()){
                int idx=pq_right.top().second;
                ans+=time[idx][2];
                wait_left.push({-(ans+time[idx][3]),idx}); 
                pq_right.pop();
                
            }
            else if(!pq_left.empty()&&n>0){
                n-=1;
                
                int idx=pq_left.top().second;
                ans+=time[idx][0];
                wait_right.push({-(ans+time[idx][1]),idx});
                pq_left.pop();
            }
            else{
                int mina=1e9;
                 if(!wait_left.empty()){
                     mina=abs(wait_left.top().first);
                 }
                
                 if(!wait_right.empty()){
                     mina=min(mina,abs(wait_right.top().first));
                 }
                // cout<<mina<<endl;
                ans=mina;
            }
         
                while(!wait_right.empty()&&abs(wait_right.top().first)<=ans){
                    
                     int pos=wait_right.top().second;
                     // cout<<pos<<endl;
                     pq_right.push({time[pos][0]+time[pos][2],pos});
                    
                    wait_right.pop();
                }
                
                while(!wait_left.empty()&&abs(wait_left.top().first)<=ans){
                    int pos=wait_left.top().second;
                    
                    pq_left.push({time[pos][0]+time[pos][2],pos});
                    wait_left.pop();
                    
                }
        }
        
        
        return ans;
        
    }
};