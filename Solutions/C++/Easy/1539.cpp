/*
    * The number of missing elements before arr[i] is: arr[i] - (i + 1)
    * With binary search we find the index left such that: arr[left] - (left + 1) >= k
    * The kth smallest element should be between arr[left - 1] and arr[left]:
        result = arr[left - 1] + (k - (arr[left - 1] - (left - 1 + 1)))
        result = k + left
*/ 

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - (mid + 1) < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return k + left;
    }
};
