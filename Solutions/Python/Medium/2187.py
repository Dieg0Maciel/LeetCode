"""
    * Considering maxTime = time[len(time) - 1] * totalTrips, the possible times are given by the array:
        T = [1, 2,..., minimunTime - 1, minimunTime, ..., maxTime]
        
    * We can loop through each value of T and calculate the number of total trips:
        numberOfTrips = 0
        for t in time:
            numberOfTrips += T[i] // t
            
    * The first T[i] for which (numberOfTrips >= totalTrips) is true corresponds to minimunTime.

    * Notice that the array T is ordered and can be divided into two regions
        left side: [1,..., minimunTime - 1] for which (numberOfTrips >= totalTrips) is false
        right side: [minimunTime, ..., maxTime] for which (numberOfTrips >= totalTrips) is true
        
    * Therefore we can perform binary search to find minimunTime.

    Remark: use left < right instead of left <= right to avoid an infinite loop.
"""

class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        left = 1
        right = time[-1] * totalTrips
        while left < right:
            mid = left + (right - left) // 2
            numberOfTrips = 0
            for t in time:
                numberOfTrips += mid // t
            if numberOfTrips >= totalTrips:
                right = mid 
            else:
                left = mid + 1
        return left 
