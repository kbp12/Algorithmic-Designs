class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int>decoded(n+1);
        decoded[0] = first;
        for(int i=0;i<n;i++){
            decoded[i+1] = decoded[i] xor encoded[i];
        }
        return decoded;
    }
};