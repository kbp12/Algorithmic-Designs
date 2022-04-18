class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<long long,long long>>> v(n,vector<pair<long long,long long>>(m,{0,0})),left,top,right,bottom;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long temp = grid[i][j], c1 = 0, c2 = 0;
                while(temp%2==0){ temp/=2; c1++;}
                while(temp%5==0){ temp/=5; c2++;}
                v[i][j].first = c1;
                v[i][j].second = c2;
            }
        }
        left=top=right=bottom=v;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                left[i][j].first += left[i][j-1].first;
                left[i][j].second += left[i][j-1].second;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=m-2;j>=0;j--){
                right[i][j].first += right[i][j+1].first;
                right[i][j].second+=right[i][j+1].second;
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                top[i][j].first += top[i-1][j].first;
                top[i][j].second += top[i-1][j].second;
            }
        }
        for(int j=0;j<m;j++){
            for(int i=n-2;i>=0;i--){
                bottom[i][j].first += bottom[i+1][j].first;
                bottom[i][j].second += bottom[i+1][j].second;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long t1,t2,t3,t4;
                long long f1,f2,f3,f4;
                long long a,b;
                a = v[i][j].first;
                b = v[i][j].second;       
                t1 = left[i][j].first;
                t2 = right[i][j].first;
                t3= top[i][j].first;
                t4 = bottom[i][j].first;
                f1 = left[i][j].second;
                f2=right[i][j].second;
                f3 = top[i][j].second;
                f4 = bottom[i][j].second;
                
                ans=max(ans,min(t3+t1-a,f3+f1-b));
                ans=max(ans,min(t3+t2-a,f3+f2-b));
                ans=max(ans,min(t4+t1-a,f4+f1-b));
                ans=max(ans,min(t4+t2-a,f4+f2-b));
            }
        }
        return ans;
    }
};