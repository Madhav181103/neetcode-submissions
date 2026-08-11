class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int u =it[0];
            int v =it[1];
            int wt =it[2];
            adj[u].push_back({v,wt});
        }
        queue<vector<int>> q;
        q.push({0,src,0});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto curr =q.front();
            q.pop();
            int stop =  curr[0];
            int node =curr[1];
            int cost = curr[2];
            if(stop>k)continue;
          
          for(auto it : adj[node]){
            int neigh=it.first;
            int wt =it.second;
            if(dist[neigh]>wt+cost){
                dist[neigh]=wt+cost;
                q.push({stop+1,neigh,dist[neigh]});
            }
          }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};