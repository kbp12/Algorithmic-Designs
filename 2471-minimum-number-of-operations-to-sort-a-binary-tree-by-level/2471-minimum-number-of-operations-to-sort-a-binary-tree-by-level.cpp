class Solution {
public:
    
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz = q.size(), i = 0;
            vector<pair<int,int>>v(sz);
            vector<bool>visit(sz,false);
            while(sz--){
                TreeNode* f = q.front(); q.pop();
                if(f->left != NULL) q.push(f->left);
                if(f->right != NULL) q.push(f->right);
                v[i] = {f->val , i};
                i++;;
            }
            sort(v.begin() , v.end());
            for(int i=0;i<v.size();i++){
                if(visit[i]) continue;
                int c = 0, j = i;
                while(!visit[j]){
                    visit[j] = true;
                    c++;
                    j = v[j].second;
                }
                ans+=c-1;
            }
        }
        return ans;
    }
};