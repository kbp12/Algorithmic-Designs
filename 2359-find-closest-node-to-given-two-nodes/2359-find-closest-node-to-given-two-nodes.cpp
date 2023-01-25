class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>v1(n,-1),v2(n,-1);
        vector<bool>visit1(n,false),visit2(n,false);
        int i = 0;
        while(true){
            if(visit1[node1]) break;
            visit1[node1] = true;
            v1[node1] = i; i++;
            if(edges[node1]==-1) break;
            node1 = edges[node1];
        }
        i = 0;
        while(true){
            if(visit2[node2]) break;
            visit2[node2] = true;
            v2[node2] = i; i++;
            if(edges[node2]==-1) break;
            node2 = edges[node2];
        }
        int ans_node = -1;
        int min_dist = INT_MAX;
        for(int i=0;i<n;i++){
            if(v1[i]!=-1 and v2[i]!=-1){
                int d = max(v1[i],v2[i]);
                if(d<min_dist){
                    min_dist = d;
                    ans_node = i;
                }
            }
        }
        return ans_node;
    }
};