class Solution {
   public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& temp, int target, int i) {
        if (i == nums.size()) {
            if (target == 0) ans.push_back(temp);
            return;
        }
        if (nums[i] <= target) {
            temp.push_back(nums[i]);
            backtrack(nums, temp, target - nums[i], i);
            temp.pop_back();
        
        }
        backtrack(nums, temp, target, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backtrack(nums, temp, target, 0);
        return ans;
    }
};
