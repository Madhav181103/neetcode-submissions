class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c : tasks ){
            freq[c-'A']++;
        }
        priority_queue<int> pq ;
        for(int f :freq){
            if(f>0) pq.push(f);
        }
        int time = 0 ;
        while(!pq.empty()){
            int cycle = n+1 ;
            vector<int> temp ;
            while(!pq.empty() && cycle){
                auto cnt = pq.top();
                pq.pop();
                if(cnt-1 > 0)temp.push_back(cnt-1);
                time++ ;
                cycle--;
            }
            for(auto it : temp){
                pq.push(it);
            }
            if(!pq.empty())time+=cycle ;
        }
        return time;
    }
};
