class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &nums,vector <int> &temp, int i , int n){

            ans.push_back(temp);
           
        
        for(int it = i ; it < n ; it++){
            if(it> i && nums[it-1]==nums[it])continue;
            temp.push_back(nums[it]);
            helper(nums,temp,it+1,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        helper(nums, temp , 0 , n );
        return ans;
    }
};
