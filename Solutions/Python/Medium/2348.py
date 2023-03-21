"""
    Consider a segment of i contiguous zeroes 0,0,...,0. You have:
      * 1 sub array of i zeroes
      * 2 sub arrays of i - 1 zeroes
        .
        .
        .
      * i - 1 sub arrays with 2 zeroes
      * i sub arrays with 1 zero
    The total count for this segment is 1 + 2 + ... + i
"""

class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        count = 0
        i = 0
        for n in nums:
            if n == 0:
                i += 1
                count += i
            else:
                i = 0
        return count
