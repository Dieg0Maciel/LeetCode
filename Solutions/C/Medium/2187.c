/*
    * Considering maxTime = time[time.size() - 1] * totalTrips, the possible times are given by the array:
        T = {1, 2,..., minimunTime - 1, minimunTime, ..., maxTime}
        
    * We can loop through each value of T and calculate the number of total trips:
        numberOfTrips = 0
        for (int j = 0; j < timeSize; j++)
            numberOfTrips += T[i] / time[j]
            
    * The first T[i] for which (numberOfTrips >= totalTrips) is true corresponds to minimunTime.
    * Notice that the array T is ordered and can be divided into two regions
        left side: {1,..., minimunTime - 1} for which (numberOfTrips >= totalTrips) is false
        right side: {minimunTime, ..., maxTime} for which (numberOfTrips >= totalTrips) is true
        
    * Therefore we can perform binary search to find minimunTime.
    Remark: use left < right instead of left <= right to avoid an infinite loop.
*/

long long minimumTime(int* time, int timeSize, int totalTrips){
    long long left = 1;
    long long right = (long long) time[timeSize - 1] * totalTrips;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long numberOfTrips = 0;
        for (int i = 0; i < timeSize; i++) {
            numberOfTrips += mid / time[i];
        }
        if (numberOfTrips >= totalTrips) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
