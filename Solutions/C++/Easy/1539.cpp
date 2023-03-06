class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        if (arr[n - 1] - n < k) {
            return k + n;
        } else {
            int i = 0;
            int missing = 0;
            for (int j = 1; j < arr[n - 1]; j++) {
                if (j == arr[i]) {
                    i++;
                } else {
                    missing++;
                }
                if (missing == k) {
                    missing = j;
                    break;
                }
            }
            return missing;
        } 
    }
};
