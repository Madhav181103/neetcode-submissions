class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n= stones.size();
        priority_queue<int> pq ; 
        for(int stone : stones){
            pq.push(stone);
        }
        while(!pq.empty() && pq.size()!=1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first==second)continue;
            else if(first<second)pq.push(second-first);
            else pq.push(first-second);
        }
        if(!pq.empty())return pq.top();
        else return 0;
    }
};
