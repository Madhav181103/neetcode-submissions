class Solution {
public:
int helper(vector<int>& nums, int k){
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
    if(nums[i-1]<=j){
        dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
    }
    else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][k];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int x:nums){
            total+=x;
        }
        if ((total + target) % 2 != 0|| total+target<0)return 0;
        int k= (total+target)/2;
        return helper(nums,k);
    }
};