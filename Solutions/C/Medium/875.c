
/*
    * The possible speeds are given by the array:
        S = {1, ... , minSpeed - 1, minSpeed, ..., max(piles)}
    * Given S[i] we can calculate eatingTime[i]
    * We can loop over S and return the smallest S[i] for which eatingTime[i] <= h
    * Since S is sorted we can use binary search:
        - if eatingTime[i] <= h we get a possible result and move to the left side of S looking for a smaller speed
        - if eatingTime[i] > h a bigger speed is required, we move to the right side of S
*/

long eatingTime(int* piles, int pilesSize, int k) {
    double speed = (double) k;
    long time = 0;
    for (int i = 0; i < pilesSize; i++) {
        double p = (double) piles[i];
        long t = (long) ceil(p / speed);
        time += t;
    }
    return time;
}

int largest(int* arr, int arrSize) {
    int result = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > result) {
            result = arr[i];
        }
    }
    return result;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int maxElement = largest(piles, pilesSize);
    int left = 1;
    int right = maxElement;
    int result = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (eatingTime(piles, mid) <= h) {
            result = min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}
