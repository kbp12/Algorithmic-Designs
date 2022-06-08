class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>v(n);
        if(k%2){
            int a = 1, b = n;
            for(int i=0;i<k;i++){
                if(i%2==0){v[i]=a; a++;}
                else{v[i]=b; b--;}
            }
            a = k/2+2;
            for(int i=k;i<n;i++){v[i]=a; a++;}
        }else{
            int a = n, b = 1;
            for(int i=0;i<k;i++){
                if(i%2==0){v[i]=a; a--;}
                else{v[i]=b; b++;}
            }
            a = k/2+1;
            for(int i=k;i<n;i++){v[i]=a; a++;}
        }
        return v;
    }
};