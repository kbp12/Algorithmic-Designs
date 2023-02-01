class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        int a = n2;
        while(a>=1){
            string s = s2.substr(0,a);
            bool yes = true;
            if(n1%a!=0){
                a--;
                continue;
            }
            for(int i=a;i<n2;i+=a){
                string t = s2.substr(i,a);
                if(t!=s){
                    yes = false;
                    break;
                }
            }
            if(yes){
                for(int i=0;i<n1;i+=a){
                    string t = s1.substr(i,a);
                    if(t!=s){
                        yes = false;
                        break;
                    }
                }
            }
            if(yes) return s;
            a--;
        }
        return "";
    }
};