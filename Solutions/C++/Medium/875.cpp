/*
    * The possible speeds are given by the array:
        S = {1, ... , minSpeed - 1, minSpeed, ..., max(piles)}
    * Given S[i] we can calculate eatingTime[i]
    * We can loop over S and return the smallest S[i] for which eatingTime[i] <= h
    * Since S is sorted we can use binary search:
        - if eatingTime[i] <= h we get a possible result and move to the left side of S looking for a smaller speed
        - if eatingTime[i] > h a bigger speed is required, we move to the right side of S
*/

class Solution {
public:
    long eatingTime(std::vector<int>& piles, int k) {
        double speed = (double) k;
        long time = 0;
        for (auto pile: piles) {
            double p = (double) pile;
            long t = (long) std::ceil(p / speed);
            time += t;
        }
        return time;
    }
    
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int maxElement = *max_element(piles.begin(), piles.end());
        int left = 1;
        int right = maxElement;
        int result = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (eatingTime(piles, mid) <= h) {
                result = std::min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
