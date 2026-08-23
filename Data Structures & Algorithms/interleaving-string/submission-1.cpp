class Solution {
public:
    bool f(string& s1, string& s2, string& s3, int i, int j,
           vector<vector<int>>& dp) {

        if (i == 0 && j == 0)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        int k = i + j - 1;

        if (i > 0 && s1[i - 1] == s3[k]) {
            if (f(s1, s2, s3, i - 1, j, dp))
                return dp[i][j] = true;
        }

        if (j > 0 && s2[j - 1] == s3[k]) {
            if (f(s1, s2, s3, i, j - 1, dp))
                return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(s1, s2, s3, n, m, dp);
    }
};