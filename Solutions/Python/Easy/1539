class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        n = len(arr)
        if arr[n - 1] - n < k:
            return k + n
        else:
            i, missing = 0, 0
            for j in range(1, arr[n - 1]):
                if j == arr[i]:
                    i += 1
                else:
                    missing += 1
                if missing == k:
                    return j
