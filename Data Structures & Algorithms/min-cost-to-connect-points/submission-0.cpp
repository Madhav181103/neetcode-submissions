class Solution {
public:
    typedef pair<int, int> P;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMST(n, false);

        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int wt = p.first;
            int node = p.second;

            if (inMST[node] == true)
                continue;

            inMST[node] = true;
            sum += wt;

            for (int neighbor = 0; neighbor < n; neighbor++) {

                if (inMST[neighbor] == false) {

                    int neighbor_wt =
                        abs(points[node][0] - points[neighbor][0]) +
                        abs(points[node][1] - points[neighbor][1]);

                    pq.push({neighbor_wt, neighbor});
                }
            }
        }

        return sum;
    }
};