class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        vector<int> temp;
        backtrack(nums, ans, visited, temp);
        return ans;
    }
    void backtrack(vector<int>& nums,vector<vector<int>>& ans, vector<bool>& visited,
                   vector<int>& temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i])continue;

            temp.push_back(nums[i]);
            visited[i]=true;
 
            backtrack(nums,ans,visited,temp);

            temp.pop_back();
            visited[i]=false;
        }
    }
};