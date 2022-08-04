class DSU{
	private:
		vector<int> parent;
		vector<int> rank;
	public:
        DSU(int n){
            parent = vector<int>(n,-1);
            rank = vector<int>(n,1);
        }
    
		int find(int x){
			if(parent[x]<0) return x;
		    return parent[x]=find(parent[x]);
		}
    
		void merge(int a,int b){
			int parent_a = find(a);
			int parent_b = find(b);
			if(parent_a == parent_b){
                return;
            }
			if(rank[parent_a] > rank[parent_b]){
				parent[parent_b] = parent_a;
			}else if(rank[parent_a] < rank[parent_b]){
				parent[parent_a] = parent_b;
			}
			else{
				parent[parent_b] = parent_a;
				rank[parent_a]++;
			}
            return;
		}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][0]-1, b = edges[i][1]-1;
            int pa = dsu.find(a);
            int pb = dsu.find(b);
            if(pa==pb){
                ans = edges[i];
                //break;
            }else{
                dsu.merge(a,b);
            }
        }
        return ans;
    }
};