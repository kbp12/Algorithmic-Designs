class Solution {
public:
    vector<string> invalidTransactions(vector<string>& t) {
        int n = t.size();
        vector<string>names(n);
        vector<int>times(n);
        vector<int>amounts(n);
        vector<string>cities(n);
        for(int i=0;i<n;i++){
            string name = "";
            int s = t[i].size();
            int j =0;
            while(j<s){
                if(t[i][j]==','){
                    break;
                }else{
                    name+=t[i][j];
                    j++;
                }
            }
            j++;
            int time = 0;
            while(j<s){
                if(t[i][j]==','){
                    break;
                }else{
                    time = time*10+(t[i][j]-'0');
                    j++;
                }
            }
            j++;
            int amount = 0;
            while(j<s){
                if(t[i][j]==','){
                    break;
                }else{
                    amount = amount*10 + (t[i][j]-'0');
                    j++;
                }
            }
            j++;
            string city = "";
            while(j<s){
                city+=t[i][j];
                j++;
            }
            names[i] = name;
            times[i] = time;
            amounts[i] = amount;
            cities[i] = city;
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(amounts[i]>1000){
                ans.push_back(t[i]);
                continue;
            }
            for(int j=0;j<n;j++){
                if(i!=j && names[i]==names[j] && abs(times[i]-times[j])<=60 && cities[i]!=cities[j]){
                    ans.push_back(t[i]);
                    break;
                }
            }
        }
        return ans;
    }
};