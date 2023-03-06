"""
    Bottom-up iterative DP solution.
    dp[i][j] is the minimum number of operations required to convert word1 of size i
    to word2 of size j. If the characters are equal we can perform only one operation:
        NOTHING:  from dp[i - 1][j - 1]  add 0 operations to obtain  dp[i][j]
    If the characters are different we can perform only 3 operations:
        REPLACE: from dp[i - 1][j - 1]  add 1 operation to obtain dp[i][j]
        DELETE: from dp[i - 1][j]  add 1 operations to obtain  dp[i][j]
        INSERT: from dp[i][j - 1]  add 1 operations to obtain  dp[i][j]
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
