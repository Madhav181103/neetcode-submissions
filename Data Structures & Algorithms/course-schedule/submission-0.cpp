class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> temp;
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            temp.push_back(node);
            for (auto neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        return temp.size() == numCourses;
    }
};