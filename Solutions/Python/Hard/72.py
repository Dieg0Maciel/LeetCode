"""
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
"""

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        dp: List[List[int]] = [[0]*(len(word2) + 1) for i in range(len(word1) + 1)]
        for i in range(len(word1) + 1):
            dp[i][0] = i
        for j in range(len(word2) + 1):
            dp[0][j] = j
        for i in range(1, len(word1) + 1):
            for j in range(1, len(word2) + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])
        return dp[len(word1)][len(word2)]
