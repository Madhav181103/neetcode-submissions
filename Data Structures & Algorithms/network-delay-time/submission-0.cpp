class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto e : times) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            for (auto [neigh, time] : adj[node]) {
                if (dist[neigh] > dist[node] + time) {
                    dist[neigh] = dist[node] + time;
                    pq.push({ dist[neigh] , neigh});
                }
            }
        }
        int maxi = *max_element(dist.begin()+1, dist.end());
        if (maxi == 1e9)
            return -1;
        else
            return maxi;
    }
};
