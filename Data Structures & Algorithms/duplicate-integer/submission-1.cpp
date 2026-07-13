class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int x:nums){
            mp[x]++;
        }
        for(auto it :mp){
            if(it.second>1)return true;
        }
        return false;
    }
};