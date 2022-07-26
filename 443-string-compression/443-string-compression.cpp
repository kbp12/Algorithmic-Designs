class Solution {
public:
    int compress(vector<char>& chars) {
        int siz = 0;
        int n = chars.size(),j,k=0;
        for(int i=0;i<n;){
            for(j = i+1;j<n;j++){
                if(chars[j]!=chars[i]) break;
            }
            int d = j-i;
            if(d==1){
                chars[k] = chars[i]; k++;
                siz++;
            }
            else if(d<10){ 
                chars[k] = chars[i]; k++;
                chars[k] = '0'+d; k++;
                siz+=2;
            }
            else if(d<100){
                chars[k] = chars[i]; k++;
                chars[k] = '0'+d/10; k++;
                chars[k] = '0'+d%10; k++;
                siz+=3;
            }
            else if(d<1000){
                chars[k] = chars[i]; k++;
                chars[k] = '0'+d/100; k++; d  = d%100;
                chars[k] = '0'+d/10; k++;
                chars[k] = '0'+d%10; k++;
                siz+=4;
            }
            else{
                chars[k] = chars[i]; k++;
                chars[k] = '0'+d/1000; k++; d = d%1000;
                chars[k] = '0'+d/100; k++; d = d%100;
                chars[k] = '0'+d/10; k++;
                chars[k] = '0'+d%10; k++;
                siz+=5;
            }
            i = j;
        }
        return siz;
    }
};