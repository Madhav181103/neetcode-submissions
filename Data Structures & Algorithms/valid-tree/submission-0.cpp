class Solution {
public:

    bool dfs(int node, int parent, vector<vector<int>>& adj, 
             vector<bool>& visited) {

        visited[node] = true;

        for(auto neigh : adj[node]) {

            if(!visited[neigh]) {
                if(!dfs(neigh, node, adj, visited))
                    return false;
            }
            else if(neigh != parent) {
                return false;
            }
        }

        return true;
    }

    bool hascycle(vector<vector<int>>& adj, int n, vector<bool>& visited) {
        return !dfs(0, -1, adj, visited);
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(hascycle(adj, n, visited))
            return false;

        for(auto it : visited) {
            if(it == false)
                return false;
        }

        return true;
    }
};