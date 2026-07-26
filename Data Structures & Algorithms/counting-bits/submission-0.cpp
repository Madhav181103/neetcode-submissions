class Solution {
public:
    int countset(int i){
        int count=0;
        while(i){
            if(i&1)count++;
           i = i>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(1,0);
        for(int i=1;i<=n;i++){
        int x = countset(i);
        ans.push_back(x);
        }
        return ans;
    }
};
