class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> order;

        for(auto e : prerequisites){
            int course = e[0];
            int prereq=e[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }
       
       queue<int> q;
       for(int i =0;i<numCourses;i++){
        if(indegree[i]==0) q.push(i);
       }

       while(!q.empty()){
        int node = q.front();
        q.pop();
        order.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
       }
       if (order.size()<numCourses) return {};
        return order;
    }
};