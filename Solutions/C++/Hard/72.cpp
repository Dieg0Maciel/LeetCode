/*
    dp[i][j] is the minimum number of operations required to convert word1 of size i
    to word2 of size j. If the characters are equal we can perform only one operation:
        * dp[i][j] + 0 operations = dp[i + 1][j + 1]
    If the characters are different we can perform 3 operations:
        * dp[i][j] + 1 replacement = dp[i + 1][j + 1]
        * dp[i][j] + 1 deletion = dp[i + 1][j]
        * dp[i][j] + 1 insertion = dp[i][j + 1]
    For the bottom-up iterative DP solution the recursive relation can be rewritten as:
        if word1[i - 1] == word2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1]
        else:
            dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
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
