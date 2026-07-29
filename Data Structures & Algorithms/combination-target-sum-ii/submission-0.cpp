class Solution {
public:
   vector<vector<int>> ans;
    void  backtrack(vector<int>& candidates,vector<int>& temp,int target,int i){
        if(target<0)return;
        if(i==candidates.size()){
        if(target==0)ans.push_back(temp);
        return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            backtrack(candidates,temp,target-candidates[i],i+1);
            temp.pop_back();
        }
        while (i + 1 < candidates.size() &&
               candidates[i] == candidates[i + 1])
            i++;
        backtrack(candidates,temp,target,i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        backtrack(candidates,temp,target,0);
        return ans;
    }
};
