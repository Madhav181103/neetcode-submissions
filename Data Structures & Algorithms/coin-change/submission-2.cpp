class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,1e9));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int nottake=dp[i-1][j];
                int take=1e9;
             if(coins[i-1]<=j){
                take=1+dp[i][j-coins[i-1]];    
            }
            dp[i][j]=min(take,nottake);
        }
    }
    if(dp[n][amount]>=1e9)return -1;
    else return dp[n][amount];
    }
};