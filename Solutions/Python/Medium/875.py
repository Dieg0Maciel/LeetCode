"""
    * The possible speeds are given by the array:
        S = [1, ... , minSpeed - 1, minSpeed, ..., max(piles)]
    * Given S[i] we can calculate eatingTime[i]
    * We can loop over S and return the smallest S[i] for which eatingTime[i] <= h
    * Since S is sorted we can use binary search:
        - if eatingTime[i] <= h we get a possible result and move to the left side of S looking for a smaller speed
        - if eatingTime[i] > h a bigger speed is required, we move to the right side of S
"""

class Solution:
    def eatingTime(self, piles: List[int], k: int) -> int:
        time = 0
        for pile in piles:
            time += math.ceil(pile / k)
        return time

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        result = right
        while left <= right:
            mid = left + (right - left) // 2
            if self.eatingTime(piles, mid) <= h:
                result = min(result, mid)
                right = mid - 1
            else:
                left = mid + 1
        return result 
