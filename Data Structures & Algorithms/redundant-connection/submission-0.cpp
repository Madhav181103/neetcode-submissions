class Solution {
   public:
    class Disjointset {
       public:
        vector<int> size, parent;
        Disjointset(int n) {
            size.resize(n,1);
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int findparent(int node) {
            if (parent[node] == node)
                return node;
            else
                return parent[node] = findparent(parent[node]);
        }
        void unionbysize(int u , int v){
            int ultu = findparent(u);
            int ultv = findparent(v);
            if(ultu == ultv) return;
            if(size[ultu]>size[ultv]){
                parent[ultv] = ultu;
                size[ultu]+=size[ultv];
            }
            else {
                parent[ultu]=ultv;
                size[ultv]+=size[ultu];
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans(2,0);
        int n = edges.size();
        Disjointset dsu(n+1);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            if(dsu.findparent(u)==dsu.findparent(v)){
                ans[0]=u;
                ans[1]=v;
            }
            dsu.unionbysize(u,v);
        }
        return ans;
    }
};
