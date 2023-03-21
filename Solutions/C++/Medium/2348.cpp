/*
    Consider a segment of i contiguous zeroes 0,0,...,0. You have:
      * 1 sub array of i zeroes
      * 2 sub arrays of i - 1 zeroes
        .
        .
        .
      * i - 1 sub arrays with 2 zeroes
      * i sub arrays with 1 zero
    The total count for this segment is 1 + 2 + ... + i
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long i = 0;
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == 0) {
                i++;
                count += i;
            } else {
                i = 0;
            }
        }
        return count;
    }
};
