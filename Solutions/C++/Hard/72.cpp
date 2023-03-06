/*
    Bottom-up iterative DP solution.
    dp[i][j] is the minimum number of operations required to convert word1 of size i
    to word2 of size j. If the characters are equal we can perform only one operation:
        NOTHING:  from dp[i - 1][j - 1]  add 0 operations to obtain  dp[i][j]
    If the characters are different we can perform 3 operations:
        REPLACE: from dp[i - 1][j - 1]  add 1 operation to obtain dp[i][j]
        DELETE: from dp[i - 1][j]  add 1 operations to obtain  dp[i][j]
        INSERT: from dp[i][j - 1]  add 1 operations to obtain  dp[i][j]
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j < n + 1; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int tmp = std::min(dp[i - 1][j], dp[i][j - 1]);
                    dp[i][j] = 1 + std::min(dp[i - 1][j - 1], tmp);
                }
            }
        }
        return dp[m][n];
    }
};
